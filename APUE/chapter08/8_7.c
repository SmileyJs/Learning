#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char const *argv[])
{
	pid_t pid;

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
	}
	else if (0 == pid) {
		exit(0);
	}
	else {
		sleep(10);
	}

	return 0;
}