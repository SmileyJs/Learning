#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>

void sig_int(int signo)
{
	printf("%s\n", __FUNCTION__);
}

void sig_quit(int signo)
{
	printf("%s\n", __FUNCTION__);
}

void sig_chld(int signo)
{
	printf("%s\n", __FUNCTION__);
}

int my_system(const char *cmd)
{
	pid_t pid;
	int status = 0;
	sigset_t saveMask, childMask;
	struct sigaction intSave, quitSave, ignore;

	ignore.sa_handler = SIG_IGN;
	sigemptyset(&ignore.sa_mask);
	ignore.sa_flags = 0;

	if (0 > sigaction(SIGINT, &ignore, &intSave)) {
		printf("sigaction failed!\n");
	}

	if (0 > sigaction(SIGQUIT, &ignore, &quitSave)) {
		printf("sigaction failed!\n");
	}

	sigemptyset(&childMask);
	sigaddset(&childMask, SIGCHLD);

	if (0 > sigprocmask(SIG_BLOCK, &childMask, &saveMask)) {
		printf("sigprocmask failed!\n");
	}

	if (NULL == cmd) {
		printf("argument error!\n");
		return -1;
	}

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
	}
	else if (0 == pid) {
		if (0 > sigaction(SIGINT, &intSave, NULL)) {
			printf("sigaction failed\n");
		}
		if (0 > sigaction(SIGQUIT, &quitSave, NULL)) {
			printf("sigaction failed!\n");
		}

		if (0 > sigprocmask(SIG_BLOCK, &saveMask, NULL)) {
			printf("sigprocmask failed!\n");
		}

		execl("/bin/sh", "sh", "-c", cmd, (char*)0);
		_exit(0);
	}
	else {
		while (0 > waitpid(pid, &status, 0)) {
			if (errno != EINTR) {
				status = -1;
				break;
			}
		}
	}

	if (0 > sigaction(SIGINT, &intSave, NULL)) {
		printf("sigaction failed!\n");
	}

	if (0 > sigaction(SIGQUIT, &quitSave, NULL)) {
		printf("sigaction failed!\n");
	}

	if (0 > sigprocmask(SIG_SETMASK, &saveMask, NULL)) {
		printf("sigprocmask failed!\n");
	}

	return status;
}

int
main(int argc, char const *argv[])
{
	if (SIG_ERR == signal(SIGINT, sig_int)) {
		printf("signal failed!\n");
	}

	if (SIG_ERR == signal(SIGQUIT, sig_quit)) {
		printf("signal failed!\n");
	}

	if (SIG_ERR == signal(SIGCHLD, sig_chld)) {
		printf("signal failed!\n");
	}

	my_system("/bin/ed");

	while (1) {
		printf("main end\n");
		sleep(1);
	}
 
	return 0;
}