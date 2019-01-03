#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINE 1024

int
main(int argc, char const *argv[])
{
	FILE *fp;

	if (NULL == (fp = popen("ls -ls 2>&1", "r"))) {
		printf("popen failed!\n");
		return -1;
	}

	char line[MAX_LINE];
	while (NULL != fgets(line, MAX_LINE, fp)) {
		if (EOF == fputs(line, stderr)) {
			printf("fputs error!\n");
			exit(-1);
		}
	}

	return 0;
}