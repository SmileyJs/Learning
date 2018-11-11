#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void sig_handler(int sig)
{
	printf("%s signal = %d\n", __FUNCTION__, sig);

	pid_t pid;
	int status;

	if (SIG_ERR == signal(SIGCLD, sig_handler))
		printf("signal execute failed!\n");

	if (-1 == (pid = wait(&status)))
		printf("wait failed!\n");
}

int
main(int argc, char const *argv[])
{
	pid_t pid;

	if (SIG_ERR == signal(SIGCLD, sig_handler))
		printf("signal execute failed\n");

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
	}
	else if (0 == pid) {
		sleep(2);
		_exit(0);
	}

	pause();

	return 0;
}