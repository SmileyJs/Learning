#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PAGER "${PAGER:-more}"

#define MAXLINE 1024

int
main(int argc, char const *argv[])
{
	if (2 != argc) {
		printf("argument error!\n");
		return -1;
	}

	FILE *fdin, *fdout;

	if (NULL == (fdin = fopen(argv[1], "r"))) {
		printf("fopen failed!\n");
		return -1;
	}

	if (NULL == (fdout = popen(PAGER, "w"))) {
		printf("popen failed!\n");
		return -1;
	}

	char buf[MAXLINE];

	while (NULL != fgets(buf, MAXLINE, fdin)) {
		if (EOF == fputs(buf, fdout)) {
			printf("fputs failed\n");
			return -1;
		}
	}

	if (0 != ferror(fdin)) {
		printf("read failed\n");
	}

	if (-1 == pclose(fdout)) {
		printf("pclose failed\n");
	}

	pause();

	return 0;
}