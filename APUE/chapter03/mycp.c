#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

static const unsigned int SIZE = 4096;

int
main(int argc, char const *argv[])
{
	int n = -1;
	char buf[SIZE];

	while (0 < (n = read(STDIN_FILENO, buf, SIZE))) {
		if (n != (write(STDOUT_FILENO, buf, n))) {
			printf("write failed!\n");
			return -1;
		}
	}

	if (n < 0) {
		printf("read failed\n");
	}

	return 0;
}