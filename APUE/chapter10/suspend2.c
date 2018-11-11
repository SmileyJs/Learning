#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

volatile sig_atomic_t quitFlag;

void sig_handler(int signo)
{
	if (signo == SIGINT) {
		printf("SIGINT\n");
	}
	else if (signo == SIGQUIT) {
		printf("SIGQUIT\n");
		quitFlag = 1;
	}
}

int
main(int argc, char const *argv[])
{
	sigset_t newmask, oldmask, waitmask;

	if (SIG_ERR == signal(SIGQUIT, sig_handler)) {
		printf("signal failed!\n");
	}

	if (SIG_ERR == signal(SIGINT, sig_handler)) {
		printf("signal failed!\n");
	}

	sigemptyset(&newmask);
	sigemptyset(&waitmask);
	sigaddset(&newmask, SIGQUIT);

	if (0 > sigprocmask(SIG_BLOCK, &newmask, &oldmask)) {
		printf("sigprocmask failed!\n");
	}

	while (quitFlag == 0)
		sigsuspend(&waitmask);
	quitFlag = 0;

	if (0 > sigprocmask(SIG_SETMASK, &oldmask, NULL)) {
		printf("sigprocmask failed\n");
	}

	return 0;
}