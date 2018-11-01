#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void mysetbuf(FILE *fp, char *buf)
{
	int mode;

	if (fp == stderr) {
		mode = _IONBF;
	}
	else if (fp == stdin || fp == stdout) {
		mode = _IOLBF;
	}
	else {
		mode = _IOFBF;
	}

	if (NULL == buf) {
		mode = _IONBF;
	}

	setvbuf(fp, buf, mode, BUFSIZ);
}

int
main(int argc, char const *argv[])
{
	FILE *fp;
	char buf[BUFSIZ] = {0};
	char rb[BUFSIZ] = {0};

	if (NULL == (fp = fopen("tmp", "w+"))) {
		printf("fopen failed!%s\n", strerror(errno));
		return -1;
	}

	mysetbuf(fp, buf);

	fputs("hello world!", fp);

	if (NULL == fgets(rb, sizeof(rb), fp)) {
		printf("fgets failed!%s\n", strerror(errno));
		if (!feof(fp)) return -1;
	}

	printf("before flush %s\n", rb);

	fflush(fp);
	rewind(fp);

	if (NULL == fgets(rb, sizeof(rb), fp)) {
		printf("fgets failed!%s\n", strerror(errno));
		if (!feof(fp)) return -1;
	}

	printf("after flush %s\n", rb);

	return 0;
}