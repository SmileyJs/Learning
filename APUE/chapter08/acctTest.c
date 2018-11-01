#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>


int
main(int argc, char const *argv[])
{
	pid_t pid;

	if (0 > (pid = fork())) {
		printf("frok 1 failed!\n");
		return -1;
	}
	else if (pid > 0) {
		sleep(2);
		exit(2);
	}

	if (0 > (pid = fork())) {
		printf("fork 2 failed!\n");
		return -1;
	}
	else if (0 < pid) {
		sleep(4);
		abort();
	}

	if (0 > (pid = fork())) {
		printf("fork 3 failed!\n");
		return -1;
	}
	else if (pid < 0) {
		execl("/bin/dd", "dd", "if=/etc/passwd", "of=/dev/null", (char*)0);
		exit(7);
	}

	if (0 > (pid = fork())) {
		printf("fork 4 failed!\n");
		return -1;
	}
	else if(0 < pid) {
		sleep(8);
		exit(0);
	}

	sleep(6);
	kill(getpid(), SIGKILL);
	exit(6);

	return 0;
}