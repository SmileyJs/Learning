#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <setjmp.h>

#define MAXLINE 256

static jmp_buf env_alrm;

void sig_handler(int signo)
{
	printf("signal alarm\n");
	longjmp(env_alrm, 1);
}

typedef void(*SigFunc)(int);

SigFunc
mySignal(int sig, SigFunc func)
{
	struct sigaction act, oact;

	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	// if (sig == SIGALRM)
#ifdef SA_INTERRUPT // only linux defined!
		// act.sa_flags |= SA_INTERRUPT;
#endif
	// else
		act.sa_flags |= SA_RESTART;

	if (-1 == sigaction(sig, &act, &oact)) {
		printf("sigaction failed!\n");
		return SIG_ERR;
	}

	return oact.sa_handler;
}

int
main(int argc, char const *argv[])
{
	if (SIG_ERR == mySignal(SIGALRM, sig_handler)) {
		printf("mySignal failed!\n");
	}

	if (0 != setjmp(env_alrm)) {
		printf("read time out\n");
		return -1;
	}

	alarm(5);
	// pause();

	int n;
	char line[MAXLINE];

	if (-1 == (n = read(STDIN_FILENO, line, MAXLINE))) {
		printf("read failed!\n");
	}
	alarm(0);

	write(STDOUT_FILENO, line, n);

	printf("signal end\n");

	return 0;
}