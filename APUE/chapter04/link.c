#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int
main(int argc, char const *argv[])
{
	if (0 != symlink("newBar", "linkBar")) {
		printf("symlink failed!\n");
		return -1;
	}

	char buf[32];

	if (0 > readlink("linkBar", buf, sizeof(buf))) {
		printf("readlink failed!\n");
		return -1;
	}

	printf("buf is %s\n", buf);

	return 0;
}