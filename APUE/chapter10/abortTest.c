#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void my_abort(void)
{
	printf("%s\n", __FUNCTION__);

	sigset_t mask;
	struct sigaction action;

	if (0 > sigaction(SIGABRT, NULL, &action)) {
		printf("sigaction failed!\n");
	}

	if (action.sa_handler == SIG_IGN) {
		action.sa_handler = SIG_DFL;
		sigaction(SIGABRT, &action, NULL);
	}

	if (action.sa_handler == SIG_DFL)
		fflush(NULL);

	sigfillset(&mask);
	sigdelset(&mask, SIGABRT);

	if (0 > sigprocmask(SIG_BLOCK, &mask, NULL)) {
		printf("sigprocmask failed!\n");
	}

	kill(getpid(), SIGABRT);

	fflush(NULL);

	action.sa_handler = SIG_DFL;
	sigaction(SIGABRT, &action, NULL);

	if (sigprocmask(SIG_SETMASK, &mask, NULL)) {
		printf("sigprocmask failed!\n");
	}

	kill(getpid(), SIGABRT); // one more time?? why?
	exit(0);
}

int
main(int argc, char const *argv[])
{
	printf("main start\n");

	my_abort();

	printf("main end\n");

	return 0;
}