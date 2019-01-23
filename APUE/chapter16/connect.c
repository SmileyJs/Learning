#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

static const int MAXSLEEP = 128;

// 16_10
/*
int
connect_retry(int fd, const struct sockaddr *addr, socklen_t addrlen)
{
	for (int num = 1; num <= MAXSLEEP; num <<= 1) {
		if (0 == connect(fd, addr, addrlen)) {
			return 0;
		}
		printf("connect failed!\n");

		sleep(num);
	}

	return -1;
}
*/

// 16_11
int
connect_retry(int domain, int type, int protocol, const struct sockaddr *addr, socklen_t addrlen)
{
	for (int num = 1; num <= MAXSLEEP; num <<= 1) {
		int fd;
		if (-1 == (fd = socket(domain, type, protocol))) {
			printf("socket failed!\n");
			return -1;
		}

		if (0 == connect(fd, addr, addrlen)) {
			return fd;
		}
		
		printf("connect failed!\n");

		sleep(num);
	}

	return -1;
}

int 
initServer(int type, const struct sockaddr *addr, socklen_t len, int qlen)
{
	int fd;

	if (-1 == (fd = socket(addr->sa_family, type, 0))) {
		printf("socket failed!\n");
		return -1;
	}

	if (-1 == bind(fd, addr, len)) {
		printf("bind failed! %s\n", strerror(errno));
		close(fd);
		return -1;
	}

	if (-1 == listen(fd, qlen)) {
		printf("listen failed! %s\n", strerror(errno));
		close(fd);
		return -1;
	}

	return 0;
}

int
main(int argc, char const *argv[])
{
	int fd;

	struct sockaddr addr;
	socklen_t len = 32;

	if (-1 == (fd = connect_retry(AF_INET, SOCK_STREAM, fd, &addr, 32))) {
		printf("connect_retry failed!\n");
		return -1;
	}

	close(fd);

	return 0;
}