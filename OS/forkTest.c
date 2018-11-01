#include <stdio.h>
#include <unistd.h>

static int count = 0;

int
main(int argc, char const *argv[])
{
	pid_t pid;
	// int count = 0;

	pid = fork();

	if (0 > pid) {
		printf("fork failed\n");
		return -1;
	}
	else if (0 == pid) {
		printf("clild process\n");
		count++;
		char* argv[] = {NULL};
		char* env[] = {NULL};
		execve("testCount", argv, env);
	}
	else {
		printf("father process\n");
		count++;
		// system("kill -9 $(pidof testCount)");
	}

	// printf("%d\n", getpid());

	return 0;
}