#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <setjmp.h>
#include <pthread.h>

static jmp_buf env_alrm;

void
sig_handler(int arg)
{
	printf("%lu %s\n", pthread_self(), __FUNCTION__);
	longjmp(env_alrm, 1);
	printf("sig_handler end\n");
}

unsigned int
sleep1(unsigned int seconds)
{
	printf("%lu %s\n", pthread_self(), __FUNCTION__);

	if (SIG_ERR == signal(SIGALRM, sig_handler)) {
		printf("signal failed!\n");
		return seconds;
	}

	alarm(seconds);
	pause();

	return (alarm(0));
}

unsigned int
sleep2(unsigned int seconds)
{
	printf("%lu %s\n", pthread_self(), __FUNCTION__);

	if (SIG_ERR == signal(SIGALRM, sig_handler)) {
		printf("signal failed\n");
		return seconds;
	}

	if (setjmp(env_alrm) == 0) {
		alarm(seconds);
		pause();
	}

	return alarm(0);
}

void
sig_int(int sig)
{
	printf("%lu %s\n", pthread_self(), __FUNCTION__);

	int i, j;
	int k;

	printf("sig_int start\n");

	for (i = 0; i != 300000; ++i) {
		for (j = 0; j != 40000; ++j)
			k += i * j;
	}

	printf("sig_int end\n");
}

int
main(int argc, char const *argv[])
{
	printf("%lu %s\n", pthread_self(), __FUNCTION__);
	printf("%d\n", SIGINT);

	if (SIG_ERR == signal(SIGINT, sig_int)) {
		printf("signal interrupt failed!\n");
	}

	sleep2(5);
	return 0;
}