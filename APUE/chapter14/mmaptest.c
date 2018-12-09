#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define COPYSIZE	4096

int
main(int argc, char const *argv[])
{
	if (argc != 3) {
		printf("argument eror!\n");
		return -1;
	}

	int ifd, ofd;
	struct stat sbuf;
	int copyed = 0, cpsz = 0;
	void *src, *dest;

	if (-1 == (ifd = open(argv[1], O_RDWR))) {
		printf("read open failed!\n");
		return -1;
	}

	if (-1 == (ofd = open(argv[2], O_CREAT | O_RDWR, S_IRWXU))) {
		printf("write open failed!\n");
		return -1;
	}

	if (-1 == fstat(ifd, &sbuf)) {
		printf("fstat failed!\n");
		return -1;
	}

	if (-1 == ftruncate(ofd, sbuf.st_size)) {
		printf("ftruncate failed!\n");
	}

	while (copyed < sbuf.st_size) {
		if (sbuf.st_size - copyed > COPYSIZE) {
			cpsz = COPYSIZE;
		}
		else {
			cpsz = sbuf.st_size - copyed;
		}

		if (MAP_FAILED == (src = mmap(0, cpsz, PROT_READ, MAP_SHARED, ifd, copyed))) {
			printf("mmap read failed! err %s\n", strerror(errno));
			return -1;
		}

		if (MAP_FAILED == (dest = mmap(0, cpsz, PROT_WRITE, MAP_SHARED, ofd, copyed))) {
			printf("mmap write failed!\n");
			return -1;
		}

		// close(ofd); 14-11

		memcpy(dest, src, COPYSIZE);
		copyed += COPYSIZE;
		munmap(dest, COPYSIZE);
		munmap(src, COPYSIZE);
	}

	return 0;
}