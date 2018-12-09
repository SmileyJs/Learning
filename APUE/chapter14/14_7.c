#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

int
set_fl(int fd, int flags)
{
	printf("%s\n", __FUNCTION__);

	int val;

	if (-1 == (val = fcntl(fd, F_GETFL, 0))) {
		printf("get failed!\n");
		return -1;
	}

	val |= flags;

	if (-1 == fcntl(fd, F_SETFL, 0)) {
		printf("set failed!\n");
		return -1;
	}

	return 0;
}

int
main(int argc, char const *argv[])
{
	int fd[2];

	if (0 > pipe(fd)) {
		printf("pipe failed!\n");
		return -1;
	}

	int n = 0;
	int i = 0;

	set_fl(fd[1], O_NONBLOCK);

	for (;;++n) {
		printf("%d", n);
		// if (1 != (i = write(fd[1], "a", 1))) {
		i = write(fd[1], "a", 1);
			printf("write failed! ret = %d\n", i);
			// break;
		// }
	}

	printf("pipe capacity is %d\n", n);
	printf("PIPE_BUF is %ld\n", sysconf(PIPE_BUF));

	return 0;
}