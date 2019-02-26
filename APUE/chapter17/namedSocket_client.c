#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stddef.h>

int
cli_conn(const char *name)
{
	printf("%s\n", __FUNCTION__);

	int fd, err, ret;
	struct sockaddr_un addr;
	int len;

	if (sizeof(addr.sun_path) < strlen(name)) {
		printf("name too long\n");
		return -1;
	}

	if (-1 == (fd = socket(AF_UNIX, SOCK_STREAM, 0))) {
		printf("socket failed! %s\n", strerror(errno));
		return -2;
	}

	memset(&addr, 0, sizeof(addr));
	addr.sun_family = AF_UNIX;
	sprintf(addr.sun_path, "%05ld_%s", (long)getpid(), "cli.socket");

	unlink(addr.sun_path);

	if (-1 == bind(fd, (struct sockaddr*)&addr, sizeof(addr))) {
		printf("bind failed! %s\n", strerror(errno));
		ret = -3;
		goto errout;
	}

	// chmod
	if (-1 == chmod(addr.sun_path, S_IRWXU)) {
		printf("chmod failed %s\n", strerror(errno));
		ret = -4;
		goto errout;
	}

	memset(&addr, 0, sizeof(addr));
	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path, name);
	len = offsetof(struct sockaddr_un, sun_path) + strlen(name);

	if (-1 == connect(fd, (struct sockaddr*)&addr, len)) {
		printf("connect failed! %s\n", strerror(errno));
		ret = -4;
		goto errout;
	}

	return fd;

errout:
	err = errno;
	close(fd);
	unlink(addr.sun_path);
	errno = err;
	return 0;
}

int
main(int argc, char const *argv[])
{
	int fd;
	fd = cli_conn("foo.socket");

	// test
	int n;
	char buf[10] = {0};
	while (0 != (n = recv(fd, buf, 10, 0))) {
		write(STDOUT_FILENO, buf, n);
	}

	return 0;
}