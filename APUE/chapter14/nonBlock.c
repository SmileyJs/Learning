#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

char buf[5000000];

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
clr_fl(int fd, int flags)
{
	printf("%s\n", __FUNCTION__);

	int val;

	if (-1 == (val = fcntl(fd, F_GETFL, 0))) {
		printf("get failed!\n");
		return -1;
	}

	val &= ~flags;

	if (-1 == fcntl(fd, F_SETFL, val)) {
		printf("set failed!\n");
		return -1;
	}

	return 0;
}

int
main(int argc, char const *argv[])
{
	int nToWrite, nWrite = 0;
	char *ptr;

	if (-1 == (nToWrite = read(STDIN_FILENO, buf, sizeof(buf)))) {
		printf("read failed!\n");
		return -1;
	}

	set_fl(STDOUT_FILENO, O_NONBLOCK);

	ptr = buf;

	while (nToWrite > 0) {
		if (-1 == (nWrite = write(STDOUT_FILENO, ptr, nToWrite))) {
			printf("write failed!\n");
		}

		fprintf(stderr, "nwrite = %d, err %s", nWrite, strerror(errno));

		if (nWrite > 0) {
			nToWrite -= nWrite;
			ptr += nWrite;
		}
	}

	clr_fl(STDOUT_FILENO, O_NONBLOCK);

	return 0;
}