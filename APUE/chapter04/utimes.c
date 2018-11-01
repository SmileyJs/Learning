#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int
main(int argc, char const *argv[])
{
	if (argc != 3) {
		printf("argument error!\n");
		return -1;
	}

	struct stat statBuf;
	int fd;
	struct timespec times[2];

	for (int i = 1; i < argc; ++i) {
		if (0 != stat(argv[i], &statBuf)) {
			printf("stat failed!\n");
			continue;
		}

		if (0 > (fd = open(argv[i], O_RDWR | O_TRUNC))) {
			printf("open failed!\n");
			continue;
		}

		times[0] = statBuf.st_atim;
		times[1] = statBuf.st_mtim;

		if (0 > futimens(fd, times)) {
			printf("futimens failed!\n");
			continue;
		}

		close(fd);
	}

	return 0;
}