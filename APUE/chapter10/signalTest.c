#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define SIG_TEST	(void(*)())	2

void sig_handle(int signo)
{
	if (signo == SIGUSR1) {
		printf("receive sigusr1\n");
	}
	else if (signo == SIGUSR2) {
		printf("receive sigusr2\n");
	}
	else if (signo == SIGTERM) {
		printf("receive signal term\n");
	}
	else {
		printf("receive signal %d\n", signo);
	}
}

int
main(int argc, char const *argv[])
{
	if (SIG_ERR == signal(SIGUSR1, sig_handle)) {
		printf("signal 1 failed!\n");
	}

	if (SIG_ERR == signal(SIGUSR2, SIG_TEST)) {
		printf("signal 2 failed!\n");
	}

	if (SIG_ERR == signal(SIGTERM, sig_handle)) {
		printf("signal 3 failed!\n");
	}

	while (1) {
		pause();
	}

	return 0;
}