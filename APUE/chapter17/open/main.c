#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/uio.h>

#ifndef OPEN_H
#include "open.h"
#endif

#define CONTORLLEN CMSG_LEN(sizeof(int))
struct cmsghdr *cmptr = NULL;

int fd_pipe(int fd[2])
{
	return socketpair(AF_UNIX, SOCK_STREAM, 0, fd);
}

int
recv_fd(int fd, ssize_t (*func)(int, const void*, size_t))
{
	struct iovec iov[1];
	struct msghdr msg;
	char *ptr;
	char buf[MAX_LINE] = {0};
	int nr, newfd;
	int status = -1;

	while (1) {
		iov[0].iov_base = buf;
		iov[0].iov_len = MAX_LINE;
		msg.msg_iov = iov;
		msg.msg_iovlen = 1;
		msg.msg_name = NULL;
		msg.msg_namelen = 0;
		if (NULL == cmptr && NULL == (cmptr = malloc(CONTORLLEN))) {
			printf("malloc failed!\n");
			return -1;
		}

		msg.msg_control = cmptr;
		msg.msg_controllen = CONTORLLEN;

		if (0 > (nr = recvmsg(fd, &msg, 0))) {	// will read the error msg and result buf! errmsg end with the buf[0] = 0 = '\0'.
			printf("recvmsg failed!\n");
			return -1;
		}
		else if (0 == nr) {
			printf("disconnected\n");
		}

		printf("receive %d buf %s len %lu\n", nr, buf, strlen(buf));

		for (ptr = buf; ptr < &buf[nr];) {
			printf("%c\n", *ptr);
			if (*ptr++ == 0) {
				if (ptr != &buf[nr - 1]) {
					printf("message format failed!\n");
					return -1;
				}
				status = 0xff & *ptr; // ??
				if (0 == status) {
					if (msg.msg_controllen < CONTORLLEN) {
						printf("msg control info error\n");
						return -1;
					}
					newfd = *(int*)CMSG_DATA(cmptr);
				}
				else {
					printf("status %d\n", status);
					newfd = status;
				}
				nr -= 2;
			}
		}

		if (nr > 0 && (*func)(STDOUT_FILENO, buf, nr) != nr) {
			printf("func failed!\n");
			return -1;
		}

		if (newfd > 0)
			return newfd;
	}

	return 0;
}

int
cs_open(char *name, int oflag)
{
	printf("name = %s oflag = %d\n", name, oflag);

	int fd[2] = {-1, -1};
	pid_t pid;
	struct iovec iov[3];
	char flag[10] = {0};

	if (0 > fd_pipe(fd)) {
		printf("fd_pipe faield!\n");
		return -1;
	}

	if (0 > (pid = fork())) {
		printf("fork faield!\n");
		return -1;
	}
	else if (0 == pid) {
		close(fd[0]);
		if (fd[1] != STDOUT_FILENO && dup2(fd[1], STDOUT_FILENO) != STDOUT_FILENO) {
			printf("dup stdout failed! %s\n", strerror(errno));
			return -1;
		}
		if (fd[1] != STDIN_FILENO && dup2(fd[1], STDIN_FILENO) != STDIN_FILENO) {
			printf("dup stdin failed!\n");
			return -1;
		}

		if (0 > execl("./opend", "opend", (char*)0)) {
			printf("execl failed!\n");
			return -1;
		}
	}

	close(fd[1]);
	sprintf(flag, " %d", oflag); // the space is important for flag!!

	iov[0].iov_base = CL_OPEN" ";
	iov[0].iov_len = strlen(CL_OPEN) + 1;
	iov[1].iov_base = name;
	iov[1].iov_len = strlen(name);
	iov[2].iov_base = flag;
	iov[2].iov_len = strlen(flag) + 1;

	int len = iov[0].iov_len + iov[1].iov_len + iov[2].iov_len;

	if (writev(fd[0], &iov[0], 3) != len) {
		printf("writev failed! %s\n", strerror(errno));
		return -1;
	}

	return recv_fd(fd[0], write);
}

int
main(int argc, char const *argv[])
{
	char buf[MAX_LINE] = {0};
	char line[MAX_LINE] = {0};

	int fd, n;

	while (fgets(line, MAX_LINE, stdin)) {
		if (line[strlen(line) - 1] == '\n') {
			line[strlen(line) - 1] = 0;
		}

		if (0 > (fd = cs_open(line, O_RDONLY))) {
			printf("cs_open failed!\n");
			continue;
		}

		while (0 < (n = read(fd, buf, MAX_LINE))) {
			if (write(STDOUT_FILENO, buf, n) != n)
				printf("write failed!\n");
		}

		if (n < 0)
			printf("read error!");

		close(fd);
	}

	return 0;
}