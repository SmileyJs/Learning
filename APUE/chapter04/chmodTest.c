#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int
main(int argc, char const *argv[])
{
	struct stat buf;

	if (0 > stat("foo", &buf)) {
		printf("stat failed!\n");
		return -1;
	}

	if (0 > chmod("foo", (buf.st_mode & ~S_IXGRP) | S_ISGID)) {
		printf("chmod foo failed!\n");
		return -1;
	}

	if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) {
		printf("chmod bar failed!\n");
		return -1;
	}

	return 0;
}