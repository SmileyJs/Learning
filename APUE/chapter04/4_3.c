#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP)

int
main(int argc, char const *argv[])
{
	int fd;

	if (0 > (fd = creat("tmpfile", RWRWRW))) {
		printf("creat failed!\n");
		return -1;
	}

	if (0 > open("tmpfile", O_RDONLY)) {
		printf("open failed!\n");
		return -1;
	}

	close(fd);

	struct stat buf;

	if (0 > stat("tmpfile", &buf)) {
		printf("stat failed!\n");
		return -1;
	}

	if (0 > chmod("tmpfile", buf.st_mode & ~S_IRUSR)) {
		printf("chmod failed!\n");
		return -1;
	}

	if (0 > open("tmpfile", O_RDONLY)) {
		printf("open failed 2!\n");
		return -1;
	}

	return 0;
}