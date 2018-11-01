#include <stdio.h>

int
main(int argc, char const *argv[])
{
	int c;

	while (EOF != (c = getc(stdin))) {
		if (EOF == putc(c, stdout))
			printf("output error!\n");
	}

	if (ferror(stdin))
		printf("input error\n");

	return 0;
}