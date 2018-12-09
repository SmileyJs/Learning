#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t
readn(int fd, void *ptr, size_t n)
{
	size_t nleft;
	ssize_t nread;

	nleft = n;

	while (nleft > 0) {
		if (-1 == (nread = read(fd, ptr, nleft))) {
			printf("read failed!\n");
			if (nleft == n) {
				return -1;
			}
			else {
				break;
			}
		}
		else if (0 == nread) {
			break;
		}

		nleft -= nread;
		ptr += nread;
	}

	return n - nleft;
}

ssize_t
writen(int fd, const void *ptr, size_t n)
{
	size_t nleft;
	ssize_t nwrite;

	nleft = n;

	while (nleft > 0) {
		if (-1 == (nwrite = write(fd, ptr, nleft))) {
			printf("write failed!\n");
			if (nleft == n) {
				return -1;
			}
			else{
				break;
			}
		}
		else if (nwrite == 0) {
				break;
		}
			
		nleft -= nwrite;
		ptr += nwrite;
	}

	return n - nleft;
}

int
main(int argc, char const *argv[])
{
	
	return 0;
}