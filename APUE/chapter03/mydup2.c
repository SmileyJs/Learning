#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char buf[] = "1234567890";


int myDup(int fd1, int fd2)
{
	printf("%s %d\n", __FUNCTION__, fd1);

	int i;	

	while ((i = dup(fd1))) {
		if (i == fd2) {
			printf("hit %d\n", i);
			return i;
		}
		printf("tmp %d\n", i);
	}

	return fd2;
}

int
main(int argc, char const *argv[])
{
	int fd;

	if (0 > (fd = open("dupTest", O_RDWR | O_CREAT))) {
		printf("failed open failed !\n");
		return -1;
	}

	if (strlen(buf) != write(fd, buf, 10)) {
		printf("write failed!\n");
		return -1;
	}

	int fd2 = myDup(fd, 10);

	lseek(fd, 0, SEEK_SET);

	char rdBuf[50];

	int n = 0;

	while (0 > (n = read(fd2, rdBuf, sizeof(rdBuf))));

	printf("%d %s\n", n, rdBuf);

	close(fd);
	close(fd2);

	return 0;
}