#include <stdio.h>

int
main(int argc, char const *argv[])
{
	int c;
	while (1) {
		printf("%d\n", c);
		++c;
		sleep(1);
	}

	return 0;
}