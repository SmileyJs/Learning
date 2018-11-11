#include <stdio.h>
#include <stdlib.h>
// #include <signal.h>

typedef int _sigset_t;
#define NSIG	65

#define sigemptyset(ptr) 	(*ptr = 0)
#define sigfillset(ptr)		(*ptr = ~(_sigset_t)0, 0)

#define BADSIG(sig)	(sig <= 0 || sig >= NSIG)

int
sigaddset(_sigset_t *set, int signo)
{
	if (BADSIG(signo)) {
		printf("bad signo\n");
		return -1;
	}

	*set  |= (1 << (signo -1));
	return 0;
}

int
sigdelset(_sigset_t *set, int signo)
{
	if (BADSIG(signo)) {
		printf("bad signo\n");
		return -1;
	}

	*set &= ~(1 << (signo - 1));
	return 0;
}

int
sigismember(const _sigset_t *set, int signo)
{
	if (BADSIG(signo)) {
		printf("bad signo\n");
		return -1;
	}

	return (*set & (1 << (signo - 1)));
}

int
main(int argc, char const *argv[])
{
	printf("%d\n", NSIG);



	return 0;
}