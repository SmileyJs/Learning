#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	int status;

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
	}
	else if (0 == pid) {
		exit(7);
	}

	if (0 > waitpid(pid, &status, 0)) {
		printf("waitpid failed\n");
	}

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
	}
	else if (0 == pid) {
		abort();
	}

	if (0 > waitpid(pid, &status, 0)) {
		printf("waitpid 2 failed!\n");
	}

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
	}
	else if (0 == pid) {
		status /= 0;
	}

	if (0 > waitpid(pid, &status, 0)) {
		printf("waitpid 3 failed\n");
	}


	return 0;
}