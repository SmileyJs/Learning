#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH | S_IWOTH)

int
main(int argc, char const *argv[])
{
	umask(0);

	if (0 > creat("foo", RWRWRW)) {
		printf("creat file foo failed!\n");
	}

	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	if (0 > creat("bar", RWRWRW)) {
		printf("creat file bar failed\n");
	}

	return 0;
}