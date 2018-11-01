#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>

#include <fcntl.h>
#include <errno.h>

char buf1[] = "ABCDEFGHIJ";
char buf2[] = "abcdefghij";

char buf3[16384];

int
main(int argc, char const *argv[])
{
	int fd;

	memset(buf3, 'j', 16384);

	if (-1 == (fd = creat("file.nohole", 0x006))) {
		printf("file create failed!\n");
		return -1;
	}

	if (10 != write(fd, buf1, 10)) {
		printf("write failed!\n");
		return -1;
	}

	// if (-1 == lseek(fd, 16384, SEEK_SET)) {
	// 	printf("lseek failed!\n");
	// 	return -1;
	// }

	if (16384 != write(fd, buf3, 16384)) {
		printf("write3 failed!\n");
		return -1;
	}

	if (10 != write(fd, buf2, 10)) {
		printf("write 2 faield!\n");
		return -1;
	}

	return 0;
}