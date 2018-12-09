#include <stdlib.h>
#include <stdio.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 7

char buf1[BUFSIZE];
char buf2[BUFSIZE];

int
main(int argc, char const *argv[])
{
	if (argc != 3) {
		printf("argument error\n");
		return -1;
	}

	int ifd, ofd;

	if (-1 == (ifd = open(argv[1], O_RDONLY))) {
		printf("read open failed!\n");
		return -1;
	}

	if (-1 == (ofd = open(argv[2], O_CREAT|O_RDWR, S_IRWXU))) {
		printf("write open failed!\n");
		return -1;
	}
	
	struct iovec vec[2];
	vec[0].iov_base = buf1;
	vec[0].iov_len = BUFSIZE;
	vec[1].iov_base = buf2;
	vec[1].iov_len = BUFSIZE;

	int n = 0;
	if (-1 == (n = readv(ifd, vec, 2))) {
		printf("readv failed!\n");
		return -1;
	}

	printf("read size = %d buf1 = %s, buf2 = %s\n", n, buf1, buf2);

	if (n != writev(ofd, vec, 2)) {
		printf("writev failed!\n");
		return -1;
	}

	return 0;
}