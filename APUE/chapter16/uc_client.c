#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <signal.h>

#define TIMEOUT 20
#define BUFLEN 1024

void
sigalrm(int signo)
{
	printf("%s", __FUNCTION__);
}

void
print_uptime(int fd, struct addrinfo *aip)
{
	int n;
	char buf[BUFLEN];

	buf[0] = 0;

	if (0 > sendto(fd, buf, 1, 0, aip->ai_addr, aip->ai_addrlen)) {
		printf("sendto failed! %s", strerror(errno));
		return;
	}

	alarm(TIMEOUT);

	if (0 > (n = recvfrom(fd, buf, BUFLEN, 0, NULL, NULL))) {
		printf("recvfrom failed %s\n", strerror(errno));
		return;
	}
		
	write(STDOUT_FILENO, buf, n);

	if (0 > n)
		printf("recv error!");
}

int
main(int argc, char const *argv[])
{
	struct addrinfo *aip, *ailist;
	struct addrinfo hint;
	int fd, err;
	struct sigaction sa;

	if (argc != 2) {
		printf("argument error!\n");
		return -1;
	}

	sa.sa_handler = sigalrm;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (0 > sigaction(SIGALRM, &sa, NULL))
		printf("sigaction failed! %s", strerror(errno));

	memset(&hint, 0, sizeof(hint));
	hint.ai_socktype = SOCK_DGRAM;
	hint.ai_canonname = NULL;
	hint.ai_addr = NULL;
	hint.ai_next = NULL;

	if (0 > (err = getaddrinfo(argv[1], "uc-ruptime", &hint, &ailist))) {
		printf("getaddrinfo failed %s\n", gai_strerror(errno));
		return -1;
	}

	for (aip = ailist; aip != NULL; aip = ailist->ai_next) {
		if (0 > (fd = socket(aip->ai_family, SOCK_DGRAM, 0))) {
			printf("socket faield! %s\n", strerror(errno));
		}
		else {
			print_uptime(fd, aip);
			return 0;
		}
	}

	return 0;
}