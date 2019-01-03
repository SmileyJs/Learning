#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE 1024

void signal_handler(int signo)
{
	printf("%s\n", __FUNCTION__);
	exit(0);
}

int
main(int argc, char const *argv[])
{
	
	if (SIG_ERR == signal(SIGPIPE, signal_handler))
		printf("signal error!\n");

	pid_t pid;
	int pfd1[2], pfd2[2];

	if (-1 == pipe(pfd1) || -1 == pipe(pfd2)) {
		printf("pipe failed!\n");
		return -1;
	}

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
		return -1;
	}
	else if (0 == pid) {
		
		printf("child %d\n", getpid());

		close(pfd1[1]);
		if (STDIN_FILENO != pfd1[0]) {
			if (STDIN_FILENO != dup2(pfd1[0], STDIN_FILENO)) {
				printf("dup2 pfd1 failed!\n");
			}
			close(pfd1[0]);
		}

		close(pfd2[0]);
		if (STDOUT_FILENO != pfd2[1]) {
			if (STDOUT_FILENO != dup2(pfd2[1], STDOUT_FILENO)) {
				printf("dup2 pfd2 failed!");
			}
			close(pfd2[1]);
		}

		if (-1 == execl("./add2", "add2", (char*)0)) {
			printf("execl failed!\n");
			return -1;
		}
	}
	else {
		close(pfd1[0]);
		close(pfd2[1]);

		char buf[MAX_LINE];

		// 15_4
		FILE *fpin, *fpout; 

		if (NULL == (fpin = fdopen(pfd2[0], "r"))) {
			printf("fpin fdopen failed!");
			return -1;
		}

		if (NULL == (fpout = fdopen(pfd1[1], "w"))) {
			printf("write fdopen failed!\n");
			return -1;
		}

		if (0 > setvbuf(fpin, NULL, _IOLBF, 0)) {
			printf("setvbuf error!\n");
			return -1;
		}

		if (0 > setvbuf(fpout, NULL, _IOLBF, 0)) {
			printf("setvbuf error!\n");
			return -1;
		}

		while (NULL != fgets(buf, MAX_LINE, stdin)) {
			int n = strlen(buf);
			// if (n != write(pfd1[1], buf, n)) {
			if (EOF == fputs(buf, fpout)) {
				printf("write failed! %d %s\n", n, strerror(errno));
				return -1;
			}

			// if (0 > (n = read(pfd2[0], buf, MAX_LINE))) {
			if (NULL == fgets(buf, MAX_LINE, fpin)) {
				printf("read failed!\n");
				return -1;
			}

			if (0 == n) {
				printf("read end of file\n");
				break;
			}

			buf[n] = 0;
			if (EOF == fputs(buf, stdout)) {
				printf("fputs failed\n");
				return -1;
			}
		}

		if (ferror(stdin)) {
			printf("fgets error!\n");
			return -1;
		}

		exit(0);
	}

	return 0;
}