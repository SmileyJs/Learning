#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int
serve_listen(const char *name)
{
	printf("%s\n", __FUNCTION__);

	int fd, size;
	struct sockaddr_un addr;
	int ret, err;

	if (strlen(addr.sun_path) > strlen(name)) {
		printf("%s name too long\n", __FUNCTION__);
		return -1;
	}

	unlink(name);

	if (-1 == (fd = socket(AF_UNIX, SOCK_STREAM, 0))) {
		printf("socket failed! %s\n", strerror(errno));
		return -2;
	}

	memset(&addr, 0, sizeof(addr));
	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path, name);
	size = offsetof(struct sockaddr_un, sun_path) + strlen(addr.sun_path);

	if (-1 == bind(fd, (struct sockaddr *)&addr, size)) {
		printf("bind failed! %s\n", strerror(errno));
		ret = -3;
		goto errout;
	}

	if (-1 == listen(fd, 10)) {
		printf("listen faield!\n");
		ret = -4;
		goto errout;
	}

	printf("UNIX domain socket bound!\n");
	return fd;

errout:
	err = errno;
	close(fd);
	errno = err;
	return ret;
}

int
serve_accept(int fd, uid_t *uidptr)
{
	printf("%s\n", __FUNCTION__);

	int cliFd, err, ret;
	struct sockaddr_un addr;
	struct stat sb;
	char *name;
	time_t staleTime;
	socklen_t len;

	if (NULL == (name = (char*)malloc(sizeof(addr.sun_path) + 1))) {
		printf("malloc failed! %s\n", strerror(errno));
		ret = -1;
		goto errout;
	}

	len = sizeof(addr);

	printf("before\n");

	if (-1 == (cliFd = accept(fd, (struct sockaddr*)&addr, &len))) {
		printf("accept failed!\n");
		ret = -2;
		goto errout;
	}

	printf("after\n");

	memcpy(name, addr.sun_path, len);
	name[len] = 0;

	if (-1 == stat(name, &sb)) {
		printf("stat failed! %s\n", strerror(errno));
		ret = -3;
		goto errout;
	}

	if (S_ISSOCK(sb.st_mode) == 0) {
		printf("not socket file!\n");
		ret = -4;
		goto errout;
	}

	if (sb.st_mode & (S_IRWXG | S_IRWXO)
		|| (sb.st_mode & S_IRWXU) != S_IRWXU) {
		printf("file mode error\n");
		ret = -5;
		goto errout;
	}

	staleTime = time(NULL) - 30;
	if (sb.st_atime < staleTime
		|| sb.st_ctime < staleTime
		|| sb.st_mtime < staleTime) {
		printf("time out\n");
		ret = -6;
		goto errout;
	}

	if (NULL != uidptr)
		*uidptr = sb.st_uid;

	unlink(name);
	free(name);
	return cliFd;

errout:
	err = errno;
	free(name);
	close(cliFd);
	errno = err;
	return ret;
}

int
main(int argc, char const *argv[])
{
	int fd;
	uid_t uid;

	if (0 > (fd = serve_listen("foo.socket"))) {
		printf("serve_listen failed!\n");
		return -1;
	}

	int cliFd = serve_accept(fd, &uid);

	// test
	char buf[10];
	sprintf(buf, "%s", "hello\n");
	send(cliFd, buf, strlen(buf), 0);

	return 0;
}