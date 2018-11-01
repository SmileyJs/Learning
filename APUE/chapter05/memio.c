#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define SIZE 48

int
main(int argc, char const *argv[])
{
	FILE *fp;
	char buf[SIZE] = {0};

	memset(buf, 'a', SIZE - 2);
	buf[SIZE-2] = '\0';
	buf[SIZE-1] = 'X';

	if (NULL == (fp = fmemopen(buf, sizeof(buf), "w+"))) {
		printf("fmemopen failed! %s\n", strerror(errno));
		return -1;
	}

	printf("initial value %s\n", buf);
	fprintf(fp, "hello, world!");
	printf("before flush %s\n", buf);
	fflush(fp);
	printf("after flush %s\n", buf);
	printf("string length %lu\n", strlen(buf));

	memset(buf, 'b', SIZE-2);
	buf[SIZE-2] = '\0';
	buf[SIZE-1] = 'X';
	fprintf(fp, "hello kitty!");
	printf("before seek %s\n", buf);
	fseek(fp, 0, SEEK_SET);
	printf("after seek %s\n", buf);
	printf("string length %lu\n", strlen(buf));

	memset(buf, 'c', SIZE-2);
	buf[SIZE-2] = '\0';
	buf[SIZE-1] = 'X';
	fprintf(fp, "hello jssss!");
	printf("before close %s\n", buf);
	fclose(fp);
	printf("after close %s\n", buf);
	printf("string length %lu\n", strlen(buf));

	return 0;
}