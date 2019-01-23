#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h>
#include <signal.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>

#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netdb.h>

#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 255
#endif

#define BUFLEN 1024
#define MAXENDPOINTS	64

void
daemonize(const char* cmd)
{
	printf("%s\n", __FUNCTION__);

	struct rlimit rl;
	pid_t pid;
	int fd0, fd1, fd2;

	umask(0);

	if (0 > getrlimit(RLIMIT_NOFILE, &rl)) {
		printf("getrlimie failed!\n");
	}

	printf("limit fileno is %lu\n", rl.rlim_max);


	for (int i = 0; i != rl.rlim_max; ++i) {
		close(i);
	}

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
	}
	else if (0 != pid) {
		exit(0);
	}

	setsid();

	// still unclear..............
	struct sigaction sa;
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (0 > sigaction(SIGHUP, &sa, NULL)) {
		printf("ignore SIGHUP failed!\n");
		return;
	}

	// page 465 system V comment
	if (0 > (pid = fork())) {
		printf("fork failed!\n");
		return;
	}
	else if (0 != pid) {
		syslog(LOG_INFO, "daemon process pid is %d!", pid);
		exit(0);
	}

	if (0 > chdir("/")) {
		printf("chdir failed\n");
	}

	fd0 = open("/dev/null", O_RDWR);
	fd1 = dup(0);
	fd2 = dup(0);

	openlog(cmd, LOG_CONS, LOG_DAEMON);
	if (0 != fd0 || 1 != fd1 || 2 != fd2) {
		syslog(LOG_ERR, "unexcepted file descriptors %d, %d, %d", fd0, fd1, fd2);
		exit(0);
	}
	syslog(LOG_INFO, "create deamon process success!");
}

int 
initServer(int type, int protocol, struct addrinfo *info, int qlen)
{
	int fd;

	if (-1 == (fd = socket(info->ai_family, type, protocol))) {
		syslog(LOG_ERR, "socket failed! %s\n", strerror(errno));
		return -1;
	}

	if (-1 == bind(fd, info->ai_addr, info->ai_addrlen)) {
		syslog(LOG_ERR, "bind failed! %s\n", strerror(errno));
		return -1;
	}

	if (type == SOCK_STREAM || type == SOCK_SEQPACKET) {
		if (-1 == listen(fd, qlen)) {
			syslog(LOG_ERR, "listen failed! %s\n", strerror(errno));
			return -1;
		}
	}

	return fd;
}

void
serve(int fd)
{
	int cfd;
	char buf[BUFLEN];
	FILE *fp;

	syslog(LOG_INFO, "%s", __FUNCTION__);

	while (1) {
		if (-1 == (cfd = accept(fd, NULL, NULL))) {
			syslog(LOG_ERR, "accept failed! %s", strerror(errno));
			exit(-1);
		}
	
		if (NULL == (fp = popen("/usr/bin/uptime", "r"))) {
			sprintf(buf, "%s", strerror(errno));
			send(cfd, buf, strlen(buf), 0);
		}
		else {
			while (fgets(buf, BUFLEN, fp)) {
				send(cfd, buf, strlen(buf), 0);
			}
			pclose(fp);
		}

		close(cfd);
	}
}

void
serve_many(int *endPoints, int count)
{
	int cfd;
	char buf[BUFLEN];
	FILE *fp;
	fd_set set;
	FD_ZERO(&set);
	int maxFD = 0;

	while (--count >= 0) {
		FD_SET(endPoints[count], &set);
		if (maxFD < endPoints[count])
			maxFD = endPoints[count];
	}

	syslog(LOG_INFO, "%s", __FUNCTION__);

	while (1) {
		if (-1 == select(maxFD+1, &set, NULL, NULL, NULL)) {
			syslog(LOG_ERR, "select failed! %s", strerror(errno));
			return;
		}

		for (int i = 0; i != count; ++i) {
			if (FD_ISSET(endPoints[i], &set)) {
				if (-1 == (cfd = accept(endPoints[i], NULL, NULL))) {
					syslog(LOG_ERR, "accept failed! %s", strerror(errno));
					exit(-1);
				}
			
				if (NULL == (fp = popen("/usr/bin/uptime", "r"))) {
					sprintf(buf, "%s", strerror(errno));
					send(cfd, buf, strlen(buf), 0);
				}
				else {
					while (fgets(buf, BUFLEN, fp)) {
						send(cfd, buf, strlen(buf), 0);
					}
					pclose(fp);
				}

				close(cfd);
			}
		}
	}
}

void
serve_fork(int fd)
{
	int cfd, status;
	pid_t pid;

	syslog(LOG_INFO, "%s", __FUNCTION__);

	while (1) {
		if (-1 == (cfd = accept(fd, NULL, NULL))) {
			syslog(LOG_ERR, "accept failed! %s", strerror(errno));
			exit(-1);
		}
	
		if (0 > (pid = fork())) {
			printf("fork failed!\n");
			return;
		}
		else if (pid == 0) {
			if (STDOUT_FILENO != dup2(cfd, STDOUT_FILENO)
				|| STDERR_FILENO != dup2(cfd, STDERR_FILENO)) {
				syslog(LOG_ERR, "ruptimed: unexcepted error!");
				exit(0);
			}
			close(cfd);
			execl("/usr/bin/uptime", "uptime", (char*)0);
			syslog(LOG_ERR, "execl uptime unexcepted error %s", strerror(errno));
		}
		else {
			close(cfd);
			waitpid(pid, &status, 0);
		}
	}
}

int
main(int argc, char const *argv[])
{
	struct addrinfo *ailist, *aip;
	int n;
	char *host;
	struct addrinfo hint;
	int err;
	int fd;
	int endPoints[MAXENDPOINTS];

	if (0 > (n = sysconf(_SC_HOST_NAME_MAX))) {
		n = HOST_NAME_MAX;
	}

	printf("host name length = %d\n", n);

	if (NULL == (host = malloc(n))) {
		printf("malloc failed!\n");
		return -1;
	}

	if (0 > gethostname(host, n)) {
		printf("gethostname failed!\n");
		return -1;
	}

	printf("host name %s\n", host);

	daemonize("ruptimed");

	memset(&hint, 0, sizeof(hint));
	hint.ai_flags = AI_CANONNAME;
	hint.ai_socktype = SOCK_STREAM;
	hint.ai_addr = NULL; 
	hint.ai_canonname = NULL;
	hint.ai_next = NULL;

	if (0 != (err = getaddrinfo(host, "ruptime", &hint, &ailist))) {
		printf("getaddrinfo failed %s!\n", gai_strerror(err));
		return -1;
	}

	int nEndPoint = 0;
	for (aip = ailist; aip != NULL; aip = ailist->ai_next) {
		if (0 < (fd = initServer(SOCK_STREAM, 0, aip, 10))) {
			// serve(fd);
			// serve_fork(fd);
			// exit(0);
			endPoints[nEndPoint++] = fd;
		}
	}

	if (nEndPoint) {
		serve_many(endPoints, nEndPoint);	
	}

	syslog(LOG_INFO, "nEndPoint = %d\n", nEndPoint);

	return 0;
}