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

	int val = 1;

	if (0 > setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(int))) {
		printf("setsockopt failed!\n");
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
	char buf[BUFLEN];
	FILE *fp;
	int n;
	char abuf[INET_ADDRSTRLEN];
	struct sockaddr *addr = (struct sockaddr *)abuf; 
	socklen_t addrlen;

	syslog(LOG_INFO, "%s", __FUNCTION__);

	while (1) {
		if (0 > (n = recvfrom(fd, buf, BUFLEN, 0, addr, &addrlen))) {
			syslog(LOG_ERR, "uc-ruptimed: recvfrom error %s", strerror(errno));
			exit(-1);
		}

		if (NULL == (fp = popen("/usr/bin/uptime", "r"))) {
			sprintf(buf, "%s", strerror(errno));
			sendto(fd, buf, strlen(buf), 0, addr, addrlen);
		}
		else {
			if (NULL != fgets(buf, BUFLEN, fp)) {
				sendto(fd, buf, strlen(buf), 0, addr, addrlen);
			}
			pclose(fp);
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

	daemonize("uc-ruptime");

	memset(&hint, 0, sizeof(hint));
	hint.ai_flags = AI_CANONNAME;
	hint.ai_socktype = SOCK_DGRAM;
	hint.ai_addr = NULL; 
	hint.ai_canonname = NULL;
	hint.ai_next = NULL;

	if (0 != (err = getaddrinfo(host, "uc-ruptime", &hint, &ailist))) {
		syslog(LOG_ERR, "getaddrinfo failed %s!\n", gai_strerror(err));
		return -1;
	}

	for (aip = ailist; aip != NULL; aip = ailist->ai_next) {
		if (0 < (fd = initServer(SOCK_DGRAM, 0, aip, 10))) {
			serve(fd);
			exit(0);
		}
	}

	return 0;
}