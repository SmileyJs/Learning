#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void
sig_alrm(int signo)
{
	printf("%s\n", __FUNCTION__);
}

unsigned int
my_sleep(unsigned int seconds)
{
	struct sigaction newact, oldact;
	unsigned int unslept = 0;
	sigset_t newMask, oldMask, susMask;

	sigemptyset(&newMask);
	sigaddset(&newMask, SIGALRM);
	sigprocmask(SIG_BLOCK, &newMask, &oldMask);

	newact.sa_handler = sig_alrm;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction(SIGALRM, &newact, &oldact);

	alarm(seconds);

	susMask = newMask;
	sigdelset(&susMask, SIGALRM);
	sigsuspend(&susMask);

	unslept = alarm(0);

	sigprocmask(SIG_SETMASK, &oldMask, NULL);

	sigaction(SIGALRM, &oldact, NULL);

	return unslept;
}

int
main(int argc, char const *argv[])
{
	my_sleep(5);
	
	return 0;
}