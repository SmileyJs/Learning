#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char const *argv[])
{
	int fd[2];
	pid_t pid;
	char line[32];
	int n = 0;

	if (0 > pipe(fd)) {
		printf("pipe faield!");
		return -1;
	}

	if (0 > (pid = (fork()))) {
		printf("fork failed!\n");
		return -1;
	}
	else if (0 == pid) {
		close(fd[1]);
		n = read(fd[0], line, 32);
		write(STDOUT_FILENO, line, n);
		printf("fd[0] = %d, fd[1] = %d\n", fd[0], fd[1]);
	}
	else {
		close(fd[0]);
		write(fd[1], "hello kitty\n", 12);
	}

	pause();

	return 0;
}