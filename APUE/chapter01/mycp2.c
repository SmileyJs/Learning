#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char const *argv[])
{
	int c;

	while ((c = getc(stdin)) != EOF) {
		if (EOF == putc(c, stdout)) {
			printf("putc failed!\n");
			exit(-1);
		}
	}

	if (ferror(stdin)) {
		printf("getc failed!\n");
		exit(-1);
	}

	return 0;
}