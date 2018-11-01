#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void sig_int(int num)
{
	printf("signal interrupt\n");
}

static const int MAXLINE = 50;

int
main(int argc, char const *argv[])
{
	char cmd[MAXLINE];
	pid_t pid;
	int status;

	if (signal(SIGINT, sig_int) == SIG_ERR) {
		printf("signal exec failed!\n");
		return -1;
	}

	printf("%%\n");

	while (fgets(cmd, MAXLINE, stdin)) {
		if (cmd[strlen(cmd) - 1] == '\n')
			cmd[strlen(cmd) - 1] = 0;

		if ((pid = fork()) < 0) {
			printf("fork failed!\n");
			exit(-1);
		}
		else if (0 == pid) {
			execlp("/bin/sh", "sh", "-c", cmd);
			printf("child process error\n");
			exit(-2);
		}
		else {
			waitpid(pid, &status, 0);
		}

		printf("%%\n");		
	}

	return 0;
}