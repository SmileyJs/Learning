#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1024

char translate(char val)
{
	char ret;
	if (val == '\n')
		return val;

	if (val < '5') {
		ret = val + 5;
	}
	else {
		ret = val - 5;
	}

	return ret;
}

int
main(int argc, char const *argv[])
{
	if (argc != 3) {
		printf("argument error!\n");
		return -1;
	}

	int ifd, ofd, rc, wc;

	if (-1 == (ifd = open(argv[1], O_RDONLY))) {
		printf("open read failed!\n");
	}

	if (-1 == (ofd = open(argv[2], O_RDWR | O_CREAT, S_IRWXU))) {
		printf("open write failed!\n");
	}

	char buf[1024] = {0};

	while (0 != (rc = read(ifd, buf, BUFSIZE))) {
		printf("read %d\n", rc);
		for (int i = 0; i != rc; ++i)
			buf[i] = translate(buf[i]);

		if (-1 == (wc = write(ofd, buf, BUFSIZE))) {
			printf("write failed!\n");
			break;
		}
	}

	return 0;
}