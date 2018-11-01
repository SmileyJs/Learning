#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int
main(int argc, char const *argv[])
{
	char path[128];
	size_t size = 128;

	int fd;

	if (NULL == getcwd(path, size)) {
		printf("getcwd failed! %s\n", strerror(errno));
		return -1;
	}

	printf("path origin %s\n", path);

	if (0 > (fd = open(".", O_RDONLY	))) {
		printf("open failed! %s\n", strerror(errno));
		return -1;
	}

	if (-1 == chdir("/home/wangjieshuai/JS")) {
		printf("chdir failed! %s\n", strerror(errno));
		return -1;
	}

	if (NULL == getcwd(path, size)) {
		printf("getcwd failed! %s\n", strerror(errno));
		return -1;
	}

	printf("path change %s\n", path);

	if (0 > fchdir(fd)) {
		printf("fchdir failed! %s\n", strerror(errno));
		return -1;
	}

	if (NULL == getcwd(path, size)) {
		printf("getcwd failed! %s\n", strerror(errno));
		return -1;
	}

	printf("path resume %s\n", path);

	return 0;
}