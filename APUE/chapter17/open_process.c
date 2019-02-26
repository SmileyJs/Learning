#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>

#define WHITE 		" \t\n"
#define MAX_ARGS	50
#define MAX_LINE	1024

#define CL_OPEN 	"open"

char errmsg[MAX_LINE];
int oflag;
char *pathname;

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

int fd_pipe(int fd[2])
{
	return socketpair(AF_UNIX, SOCK_STREAM, 0, fd);
}

int pipeTest()
{
	printf("%s\n", __FUNCTION__);

	int fd[2];
	int pid;

	if (0 > fd_pipe(fd)) {
		printf("pipe failed!\n");
		return -1;
	}

	if (0 > (pid = fork())) {
		printf("fork faield!\n");
		return -1;
	}
	else if (0 == pid) {
		close(fd[0]);

		if (fd[1] != STDIN_FILENO 
			&& dup2(fd[1], STDIN_FILENO) != STDIN_FILENO) {
			printf("failed cp fd stdin\n");
		}

		if (fd[1] != STDOUT_FILENO
			&& dup2(fd[1], STDOUT_FILENO != STDOUT_FILENO)) {
			printf("faield cp fd stdout\n");
		}

		char buf[MAX_LINE];
		int n = 0;

		sleep(1);

		n = read(fd[1], buf, MAX_LINE);
			printf("read %s\n", buf);
	
	}
	else {
		close(fd[1]);

		char tmp[10];
		sprintf(tmp, "%s", "hello");

		if (strlen(tmp) != write(fd[0], tmp, 10))
			printf("write failed! %s\n", strerror(errno));

		char buf[MAX_LINE];
		int n = 0;

		while (0 != (n = read(fd[0], buf, MAX_LINE))) {
			printf("read %s\n", buf);
		}
	}

	return 0;
}



int
main(int argc, char const *argv[])
{
	char buf[MAX_ARGS];
	sprintf(buf, "%s", "open opentest.txt 0600");
	buf_args(buf, cli_args);

	pipeTest();

	return 0;
}