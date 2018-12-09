#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <aio.h>
#include <sys/stat.h>
#include <sys/types.h>

#define NBUF	8
#define BUFSIZE	1024

enum rwop {
	UNUSED = 0,
	READPENDING,
	WRITEPENDIND
};

struct buf {
	enum rwop op;
	int last;
	struct aiocb aiocb;
	char data[BUFSIZE];
};

struct buf bufs[NBUF];

char
translate(char val)
{
	char ret;
	if (val == '\n')
		return val;

	if (val < '5') {
		ret = val + 5;
	}
	else {
		ret = val - 5;
	}

	return ret;
}

int
main(int argc, char const *argv[])
{
	if (argc != 3) {
		printf("argument error!\n");
		return -1;
	}

	int ifd, ofd, numop = 0, n, err;
	const struct aiocb *aiolist[NBUF];

	if (-1 == (ifd = open(argv[1], O_RDONLY))) {
		printf("open read failed!\n");
	}

	if (-1 == (ofd = open(argv[2], O_RDWR | O_CREAT, S_IRWXU))) {
		printf("open write failed!\n");
	}

	struct stat sbuf;
	off_t off = 0;

	if (-1 == fstat(ifd, &sbuf)) {
		printf("fstat failed!\n");
		return -1;
	}

	for (int i = 0; i != NBUF; ++i) {
		bufs[i].op = UNUSED;
		bufs[i].last = 0;
		bufs[i].aiocb.aio_buf = bufs[i].data;
		bufs[i].aiocb.aio_sigevent.sigev_notify = SIGEV_NONE;
		aiolist[i] = NULL;
	}

	while (1) {
		for (int i = 0; i != NBUF; ++i) {
			switch (bufs[i].op) {
				case UNUSED:
					if (off < sbuf.st_size) {
						bufs[i].op = READPENDING;
						bufs[i].aiocb.aio_fildes = ifd;
						bufs[i].aiocb.aio_offset = off;
						bufs[i].aiocb.aio_nbytes = BUFSIZE;

						off += BUFSIZE;
						if (off >= sbuf.st_size) {
							bufs[i].last = 1;
						}
						if (-1 == aio_read(&bufs[i].aiocb)) {
							printf("aio_read failed!\n");
							return -1;
						}
						aiolist[i] = &bufs[i].aiocb;
						numop++;
					}
					break;
				case READPENDING:
					err = aio_error(&bufs[i].aiocb);
					if (EINPROGRESS == err)
						continue;
					if (0 != err) {
						if (-1 == err) {
							printf("aio_error failed!\n");
							return -2;
						}
						else {
							printf("error %s\n", strerror(errno));
							return -2;
						}
					}

					n = aio_return(&bufs[i].aiocb);
					if (n != BUFSIZE && bufs[i].last != 1) {
						printf("aio_return failed!\n");
						return -2;
					}

					bufs[i].op = WRITEPENDIND;
					bufs[i].aiocb.aio_fildes = ofd;
					bufs[i].aiocb.aio_nbytes = n;

					for (int j = 0; j != n; ++j) {
						bufs[i].data[j] = translate(bufs[i].data[j]);
					}

					if (-1 == aio_write(&bufs[i].aiocb)) {
						printf("aio_write failed\n");
						return -2;
					}
					
					break;
				case WRITEPENDIND:
					err = aio_error(&bufs[i].aiocb);
					if (EINPROGRESS == err)
						continue;
					if (0 != err) {
						if (-1 == err) {
							printf("aio_error failed!\n");
							return -3;
						}
						else {
							printf("error %s\n", strerror(errno));
							return -3;
						}
					}

					n = aio_return(&bufs[i].aiocb);
					if (-1 == n) {
						printf("aio_return failed!\n");
						return -3;
					}
					if (n != bufs[i].aiocb.aio_nbytes) {
						printf("aio_write failed!\n");
						return -3;
					}
					aiolist[i] = NULL;
					bufs[i].op = UNUSED;
					numop--;
					break;
				default:
				break; 
			}
		}
		if (0 == numop) {
			if (off >= sbuf.st_size) {
				break;
			}
		}
		else {
			int ret = aio_suspend(aiolist, NBUF, NULL);
			if (-1 == ret) {
				printf("aio_suspend failed!\n");
				return -1;
			}
		}
	}

	bufs[0].aiocb.aio_fildes = ofd;

	if (-1 == aio_fsync(O_SYNC, &bufs[0].aiocb)) {
		printf("fsycn failed!\n");
		return -1;
	}

	return 0;
}