#include <stdio.h>

#define MAXLINE	4

int
main(int argc, char const *argv[])
{
	char buf[MAXLINE] = {0};

	int count = 0;
	while (fgets(buf, MAXLINE, stdin)) {
		printf("count = %d\n", count++);
		if (EOF == fputs(buf, stdout))
			printf("fputs failed!\n");
	}

	if (ferror(stdin))
		printf("input failed!\n");

	return 0;
}