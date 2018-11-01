#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <sys/types.h>
#include <fcntl.h>

int
main(int argc, char const *argv[])
{
	if (0 > open("tmpfile", O_RDWR)) {
		printf("open failed!\n");
		return -1;
	}

	if (0 > unlink("tmpfile")) {
		printf("unlink failed!\n");
		return -1;
	}

	printf("file unlinked!\n");
	sleep(15);
	printf("done!\n");

	return 0;
}