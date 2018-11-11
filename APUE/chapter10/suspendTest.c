#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

void show_mask(const char *s)
{
	sigset_t sigset;
	int errno_save;

	errno_save = errno;

	if (0 > sigprocmask(0, NULL, &sigset)) {
		printf("sigprocmask failed\n");
	}
	else {
		printf("%s: ", s);

		if (sigismember(&sigset, SIGALRM))
			printf("SIGALRM");
		if (sigismember(&sigset, SIGINT))
			printf("SIGINT");
		if (sigismember(&sigset, SIGUSR1))
			printf("SIGUSR1");
	}

	printf("\n");

	errno = errno_save;
}

void sig_int(int signo)
{
	show_mask(__FUNCTION__);
}

int
main(int argc, char const *argv[])
{
	sigset_t newmask, oldmask, waitmask;

	show_mask("main start");

	if (signal(SIGINT, sig_int) == SIG_ERR)
		printf("signal faield!\n");

	sigemptyset(&waitmask);
	sigemptyset(&newmask);

	sigaddset(&waitmask, SIGUSR1);
	sigaddset(&newmask, SIGINT);

	if (0 > sigprocmask(SIG_BLOCK, &newmask, &oldmask)) {
		printf("sigprocmask faield!\n");
	}

	show_mask("in critical section.");

	sigsuspend(&waitmask);

	show_mask("return form critical section");

	if (0 > sigprocmask(SIG_UNBLOCK, &newmask, &oldmask)) {
		printf("sigprocmask failed!\n");
	}

	show_mask("main end!");

	return 0;
}