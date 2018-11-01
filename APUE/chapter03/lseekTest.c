#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int
main(int argc, char const *argv[])
{
	if (-1 == lseek(0, 0, SEEK_CUR)) {
		printf("can not seek\n");
	}
	else {
		printf("seek ok\n");
	}

	return 0;
}