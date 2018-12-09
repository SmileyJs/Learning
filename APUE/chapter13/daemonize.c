#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <syslog.h>

void
daemonize()
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
		exit(0);
	}


	if (0 > chdir("/")) {
		printf("chdir failed\n");
	}

	fd0 = open("/dev/null", O_RDWR);
	fd1 = dup(0);
	fd2 = dup(0);

	openlog("daemonize", LOG_CONS, LOG_DAEMON);
	if (0 != fd0 || 1 != fd1 || 2 != fd2) {
		syslog(LOG_ERR, "unexcepted file descriptors %d, %d, %d", fd0, fd1, fd2);
		exit(0);
	}
	syslog(LOG_INFO, "create deamon process success!");
}

int
main(int argc, char const *argv[])
{
	daemonize();

	while (1) {
		sleep(1);
	}
	return 0;
}