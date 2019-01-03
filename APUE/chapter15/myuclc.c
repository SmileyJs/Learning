#include <stdio.h>
#include <ctype.h>

int
main(int argc, char const *argv[])
{
	int c;

	while (EOF != (c = getchar())) {
		if (isupper(c))
			c = tolower(c);
		if (putchar(c) == EOF)
			printf("putchar failed!\n");
		if (c == '\n')
			fflush(stdout);
	}

	return 0;
}