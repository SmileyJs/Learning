#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

char *env[] = {"USER=unknown", "PATH=/tmp", NULL};

int
main(int argc, char const *argv[])
{
	pid_t pid;

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
	}
	else if (0 == pid) {
		if (0 > execle("./showAll", "showAll1", "myarg1", "myarg2", NULL, env))
			printf("execle failed!\n");
	}

	if (waitpid(pid, NULL, 0) < 0)
		printf("waitpid failed!\n");

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
	}
	else if (0 == pid) {
		if (0 > execlp("showAll", "showAll2", "muargl1", NULL))
			printf("execlp failed %s\n", strerror(errno));
	}

	return 0;
}