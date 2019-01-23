#include <stdio.h>
#include <stdlib.h>
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

		if (0 == connect(fd, addr, addrlen)) {
			return fd;
		}
		
		printf("connect failed! %s\n", strerror(errno));

		sleep(num);
	}

	return -1;
}

void
print_uptime(int fd)
{
	int n;
	char buf[BUFLEN];

	while (0 != (n = recv(fd, buf, BUFLEN, 0))) {
		write(STDOUT_FILENO, buf, n);
	}

	if (0 > n)
		printf("recv error!");
}

int
main(int argc, char const *argv[])
{
	struct addrinfo *aip, *ailist;
	struct addrinfo hint;
	int fd, err;

	if (argc != 2) {
		printf("argument error!\n");
		return -1;
	}

	memset(&hint, 0, sizeof(hint));
	hint.ai_socktype = SOCK_STREAM;
	hint.ai_canonname = NULL;
	hint.ai_addr = NULL;
	hint.ai_next = NULL;

	if (0 > (err = getaddrinfo(argv[1], "ruptime", &hint, &ailist))) {
		printf("getaddrinfo failed %s\n", gai_strerror(errno));
		return -1;
	}

	for (aip = ailist; aip != NULL; aip = ailist->ai_next) {
		if (0 > (fd = connect_retry(aip->ai_family, SOCK_STREAM, 0, aip->ai_addr, aip->ai_addrlen))) {
			printf("connect_retry faield! %s\n", strerror(errno));
			// continue next address?
		}
		else {
			print_uptime(fd);
			return 0;
		}
	}

	return 0;
}