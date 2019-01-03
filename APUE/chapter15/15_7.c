#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

int
main(int argc, char const *argv[])
{
	pid_t pid;
	int fd[2];
	struct timeval tv;

	if (0 > pipe(fd)) {
		printf("pipe failed!\n");
		return -1;
	}

	char buf[64];

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
		return -1;
	}
	else if (pid == 0) {
		printf("child process\n");

		close(fd[1]);

		// if (0 > read(fd[0], buf, 64)) {
		// 	printf("read failed!\n");
		// 	return -1;
		// }

		// printf("%s\n", buf);

		fd_set readFd;
		FD_ZERO(&readFd);
		FD_SET(fd[0], &readFd);

		if (FD_ISSET(fd[0], &readFd)) {
			printf("set in\n");
		}

		tv.tv_sec = 5;
		tv.tv_usec = 0;

		int n = select(1, &readFd, NULL, NULL, &tv);

		if (-1 == n) {
			printf("select faield! %s\n", strerror(errno));
			return -1;
		}
		else if (0 == n) {
			printf("select return 0\n");
		}
		else {
			printf("can read\n");
		}

		close(fd[0]);
	}
	else {
		printf("parent process\n");
	
		close(fd[0]);
		sprintf(buf, "%s", "haha");
		int len = strlen(buf);

		if (len != write(fd[1], buf, len)) {
			printf("write failed!\n");
			return -1;
		}

		if (0 > waitpid(pid, NULL, 0)) {
			printf("waitpid failed!\n");
			return -1;
		}

		close(fd[1]);
	}
	
	return 0;
}