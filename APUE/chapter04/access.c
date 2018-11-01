#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int
main(int argc, char const *argv[])
{
	if (argc != 2) {
		printf("argument error!\n");
		return -1;
	}

	if (0 > access(argv[1], X_OK)) {
		printf("access error %s\n", strerror(errno));
	}
	else {
		printf("OK\n");
	}

	return 0;
}