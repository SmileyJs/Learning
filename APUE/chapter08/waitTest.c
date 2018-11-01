#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void print_exit(int status)
{
	if (WIFEXITED(status)) {
		printf("normal exit %d\n", WEXITSTATUS(status));
	}
	else if (WIFSIGNALED(status)) {
		printf("abnormal exit, signal number %d\n", WTERMSIG(status));
	}
	else if (WIFSTOPPED(status)) {
		printf("abnormal exit, signal number %d\n", WSTOPSIG(status));
	}
}

int
main(int argc, char const *argv[])
{
	pid_t pid;
	int status;

	// if (0 > (pid = fork())) {
	// 	printf("fork failed!\n");
	// }
	// else if (0 == pid) {
	// 	exit(7);
	// }

	// if (wait(&status) != pid) {
	// 	printf("wait failed!\n");
	// }
	// print_exit(status);

	// if (0 > (pid = fork())) {
	// 	printf("fork failed!\n");
	// }
	// else if (0 == pid) {
	// 	abort();
	// }

	// if (wait(&status) != pid) {
	// 	printf("wait failed!\n");
	// }
	// print_exit(status);

	// if (0 > (pid = fork())) {
	// 	printf("fork failed!\n");
	// }
	// else if (0 == pid) {
	// 	status /= 0;
	// }

	// if (wait(&status) != pid) {
	// 	printf("wait failed!\n");
	// }
	// print_exit(status);

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
	}
	else if (0 == pid) {
		if (0 > (pid = fork())) {
			printf("fork failed!\n");
		}
		else if (pid > 0) {
			// sleep(1);
			exit(0);
		}

		sleep(10);
		printf("second child, parent pid is = %d\n", getppid());
		exit(0);
	}

	if (waitpid(pid, NULL, 0) != pid)
	{
		printf("waitpid failed! %s\n", strerror(errno));
	}

	printf("end\n");

	return 0;
}