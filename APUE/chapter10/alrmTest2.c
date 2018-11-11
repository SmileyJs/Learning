#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <setjmp.h>

#define MAXLINE 256

static jmp_buf env_alrm;

void
sig_alrm(int sig)
{
	printf("%s\n", __FUNCTION__);
	longjmp(env_alrm, 1);
}

int
main(int argc, char const *argv[])
{
	int n;
	char line[MAXLINE];

	if (SIG_ERR == signal(SIGALRM, sig_alrm)) {
		printf("signal faield\n");
	}

	if (setjmp(env_alrm) != 0) {
		printf("read time out\n");
		return -1;
	}

	alarm(10);
	if (0 > (n = read(STDIN_FILENO, line, MAXLINE))) {
		printf("read faield!\n");
	}
	alarm(0);

	write(STDOUT_FILENO, line, n);

	return 0;
}