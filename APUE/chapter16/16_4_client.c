#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>

#define BUFLEN 1024
#define MAXSLEEP 128

int
connect_retry(int domain, int type, int protocol, const struct sockaddr *addr, socklen_t addrlen)
{
	for (int num = 1; num <= MAXSLEEP; num <<= 1) {
		int fd;

		if (-1 == (fd = socket(domain, type, protocol))) {
			printf("socket failed!\n");
			return -1;
		}

		if (0 == connect(fd, addr, addrlen))
			return fd;

		printf("connect failed! %s\n", strerror(errno));

		sleep(num);
	}

	return -1;
}

void
print_processCount(int fd)
{
	int n;
	char buf[BUFLEN] = {0};

	while (0 != (n = recv(fd, buf, BUFLEN, 0))) {
		write(STDOUT_FILENO, buf, n);
	}

	if (0 > n)
		printf("recv error!\n");
}

int
main(int argc, char const *argv[])
{
	struct addrinfo *ailist, *aip;
	struct addrinfo hint;
	int err;
	int fd;

	if (2 != argc) {
		printf("argument error!\n");
		return -1;
	}

	memset(&hint, 0, sizeof(hint));
	hint.ai_socktype = SOCK_STREAM;
	hint.ai_addr = NULL;
	hint.ai_canonname = NULL;
	hint.ai_next = NULL;

	if (0 != (err = getaddrinfo(argv[1], "processCount", &hint, &ailist))) {
		printf("getaddrinfo faield! %s\n", gai_strerror(err));
		return -1;
	}

	for (aip = ailist; aip != NULL; aip = ailist->ai_next) {
		if (0 < (fd = connect_retry(aip->ai_family, SOCK_STREAM, 0, aip->ai_addr, aip->ai_addrlen))) {
			print_processCount(fd);
			return 0;
		}
		else {
			printf("connect retry failed! %s\n", strerror(errno));
		}
	}

	return 0;
}