#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void set_fl(int fd, int flags)
{
	int val;
	if (0 > (val = fcntl(fd, F_GETFL, 0))) {
		printf("fcntl get failed!\n");
		return;
	}

	val |= flags;

	if (0 > fcntl(fd, F_SETFL, val))
		printf("fcntl set failed!\n");
}

int
main(int argc, char const *argv[])
{
	if (2 != argc) {
		printf("argument error!\n");
		return -1;
	}

	int val;

	if (0 > (val = fcntl(atoi(argv[1]), F_GETFL, 0))) {
		printf("fcntl exec failed!\n");
		return -1;
	}

	printf("0x%x\n", val);

	switch (val & O_ACCMODE) {
	case O_RDONLY:
		printf("read only!\n");
		break;
	case O_WRONLY:
		printf("write only!\n");
		break;
	case O_RDWR:
		printf("read and write!\n");
		break;
	default:
		printf("else\n");
	}

	if (val & O_APPEND) {
		printf("append\n");
	}
	if (val & O_NONBLOCK) {
		printf("block\n");
	}
	else if (val & O_SYNC) {
		printf("sync\n");
	}

	// set_fl(atoi(argv[1]), O_APPEND);

	// if (0 > (val = fcntl(atoi(argv[1]), F_GETFL, 0))) {
	// 	printf("fcntl exec failed!\n");
	// 	return -1;
	// }

	// if (val & O_APPEND) {
	// 	printf("append\n");
	// }
	// if (val & O_NONBLOCK) {
	// 	printf("block\n");
	// }
	// else if (val & O_SYNC) {
	// 	printf("sync\n");
	// }

	return 0;
}