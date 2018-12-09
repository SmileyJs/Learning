#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define FILESIZE 500000

int
main(int argc, char const *argv[])
{
	int fd;

	char buf[11] = "0123456789\n";

	if (-1 == (fd = open("test.txt", O_RDWR | O_CREAT, O_APPEND))) {
		printf("open failed! %s\n", strerror(errno));
		return -1;
	}


	for (int i = 0; i != FILESIZE; ++i) {
		write(fd, buf, 11);
	}

	return 0;
}