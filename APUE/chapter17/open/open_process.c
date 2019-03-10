#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>

#define WHITE 		" \t\n"
#define MAX_ARGS	50
#define MAX_LINE	1024

#define CL_OPEN 	"open"

char errmsg[MAX_LINE];
int oflag;
char *pathname;

#define CONTORLLEN CMSG_LEN(sizeof(int))
struct cmsghdr *cmptr = NULL;

int
send_fd(int fd, int fd_to_send)
{
	struct iovec iov[1];
	struct msghdr msg;
	char buf[2];

	iov[0].iov_base = buf;
	iov[0].iov_len = 2;
	msg.msg_iov = iov;
	msg.msg_iovlen = 1;
	msg.msg_name = NULL;
	msg.msg_namelen = 0;

	if (0 > fd_to_send) {
		msg.msg_control = NULL;
		msg.msg_controllen = 0;
		buf[1] = -fd_to_send;
		if (0 == buf[1])
			buf[1] = 1;
	}
	else {
		if (NULL == cmptr && NULL == (cmptr = malloc(CONTORLLEN)))
			return -1;

		cmptr->cmsg_len = CONTORLLEN;
		cmptr->cmsg_level = SOL_SOCKET;
		cmptr->cmsg_type = SCM_RIGHTS;
		msg.msg_control = cmptr;
		msg.msg_controllen = CONTORLLEN;

		*(int*)CMSG_DATA(cmptr) = fd_to_send;
		buf[1] = 0;
	}
	buf[0] = 0;

	if (2 != sendmsg(fd, &msg, 0)) { // size of buf?? don't include control info.
		printf("sendmsg failed!\n");
		return -1;
	}

	return 0;
}

int
send_err(int fd, int errCode, const char* msg)
{
	int n;

	if (0 < (n = strlen(msg))) {
		if (n != write(fd, msg, n)) {
			printf("write failed!\n");
			return -1;
		}
	}

	if (errCode > 0)
		errCode = -1;

	if (0 > send_fd(fd, errCode)){
		printf("send_fd failed!\n");
		return -1;
	}

	return 0;
}

int
cli_args(int argc, char **argv)
{
	if (argc != 3 || strcmp(argv[0], CL_OPEN) != 0) {
		strcpy(errmsg, "usage: <pathname> <oflag>");
		printf("%s args error!\n", __FUNCTION__);
		return -1;
	}

	pathname = argv[1];
	oflag = atoi(argv[2]);

	return 0;
}

int
buf_args(char *buf, int (*func)(int, char**))
{
	char *ptr;
	char *argv[MAX_ARGS];
	int argc = 0;

	if (NULL == (ptr = strtok(buf, WHITE)))
		return -1;

	argv[0] = ptr;

	while (NULL != (ptr = strtok(NULL, WHITE))) {
		if (++argc >= MAX_ARGS -1)
			return -1;
		argv[argc] = ptr;
	}

	argv[++argc] = NULL;

	for (int i = 0; argv[i] != NULL; ++i) {
		printf("%s\n", argv[i]);
	}

	return (*func)(argc, argv);
}

void
handle_request(char *buf, int nread, int fd)
{
	int newfd;

	if (buf[nread - 1] != 0) {
		sprintf(errmsg, "error %s, request not null terminate", __FUNCTION__);
		send_err(fd, -1, errmsg);
		return;
	}

	if (0 > buf_args(buf, cli_args)) {
		sprintf(errmsg, "buf_args failed! %s", __FUNCTION__);
		send_err(fd, -1, errmsg);
		return;
	}

	if (0 > (newfd = open(pathname, oflag))) {
		sprintf(errmsg, "open failed! %s", __FUNCTION__);
		send_err(fd, -1, errmsg);
		return;
	}

	if (0 > send_fd(fd, newfd)) {
		printf("send_fd failed!\n");
	}

	close(newfd);
}

int
main(void)
{
	int nread;
	char buf[MAX_LINE] = {0};

	while (1) {
		if (0 > (nread = read(STDIN_FILENO, buf, MAX_LINE))) {
			printf("open process read failed!\n");
			return -1;
		}
		else if (nread == 0) {
			break;
		}

		sprintf(errmsg, "read buf! %s", buf);
		send_err(STDOUT_FILENO, -1, errmsg);

		handle_request(buf, strlen(buf) + 1, STDOUT_FILENO);
	}

	return 0;
}