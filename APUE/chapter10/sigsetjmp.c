#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <setjmp.h>
#include <pthread.h>

static sigjmp_buf jmpbuf;
static volatile sig_atomic_t canjump;

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

void sig_alrm(int signo)
{
	show_mask("sig_alrm");
	printf("%s %lu\n", __func__, pthread_self());
}

void sig_usr1(int signo)
{
	if (0 == canjump)
		return;

	printf("%s %lu\n", __func__, pthread_self());

	show_mask("sig_usr1 start");

	time_t start;

	alarm(3);
	start = time(NULL);

	show_mask("sig_usr1 before alarm");

	while((start + 5) > time(NULL));

	show_mask("sig_usr1 end");

	siglongjmp(jmpbuf, 1);
}

int
main(int argc, char const *argv[])
{
	printf("%d\n", SIGUSR1);
	printf("%s %lu\n", __func__, pthread_self());

	if (SIG_ERR == signal(SIGALRM, sig_alrm)) {
		printf("signal alarm failed!\n");
	}

	if (SIG_ERR == signal(SIGUSR1, sig_usr1)) {
		printf("signal usr1 failed!\n");
	}

	show_mask("main start");

	if (sigsetjmp(jmpbuf, 1)) {
		show_mask("main end");
		exit(0);
	}

	canjump = 1;

	while (1) {
		pause();
	}

	return 0;
}