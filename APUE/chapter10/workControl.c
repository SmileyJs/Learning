#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define MAXLINE	1024

void sig_tstp(int signo)
{
	printf("%s start\n", __FUNCTION__);

	signal(SIGTSTP, SIG_DFL);

	sigset_t mask;
	sigemptyset(&mask);
	sigaddset(&mask, SIGTSTP);
	sigprocmask(SIG_UNBLOCK, &mask, NULL);

	kill(getpid(), SIGTSTP);

	signal(SIGTSTP, sig_tstp);

	printf("%s end\n", __FUNCTION__);
}

int
main(int argc, char const *argv[])
{
	int n;
	char line[MAXLINE];

	printf("stop %d continue %d\n", SIGTSTP, SIGCONT);

	if (signal(SIGTSTP, SIG_IGN) == SIG_DFL) {
		signal(SIGTSTP, sig_tstp);
	}

	while (0 < (n = read(STDIN_FILENO, line, MAXLINE))) {
		if (n != write(STDOUT_FILENO, line, n))
			printf("wirte faield!\n");
	}

	if (n < 0)
		printf("read faield\n");

	return 0;
}