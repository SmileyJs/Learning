#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int
main(int argc, char const *argv[])
{
	struct stat statbuf;

	for (int i = 0; i != argc; ++i) {

		if (-1 == stat(argv[i], &statbuf)) {
			printf("stat failed! %s\n", strerror(errno));
			return -1;
		}

		printf("%s dev = %d/%d", argv[i], major(statbuf.st_dev), minor(statbuf.st_dev));

		if (S_ISCHR(statbuf.st_mode) || S_ISBLK(statbuf.st_mode)) {
			printf("%s rdev = %d/%d", S_ISCHR(statbuf.st_mode) ? "charactor":"block",
				major(statbuf.st_rdev), minor(statbuf.st_rdev));
		}

		printf("\n");
	}

	return 0;
}