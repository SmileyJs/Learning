#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int
my_system(const char* cmd)
{
	if (!cmd) {
		printf("argument error!\n");
		return 1;
	}

	pid_t pid;
	int status;

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
		status = -1;
	}
	else if (0 == pid) {
		execl("/bin/bash", "bash", "-c", cmd, (char*)0);
		_exit(127);
	}
	else {
		while (0 > waitpid(pid, &status, 0)) {
			if (errno != EINTR) {
				status = -1;
				break;
			}
		}
	}

	return status;
} 

void  print_exit(int status)
{
	if (WIFEXITED(status)) {
		printf("normal ternination %d\n", WEXITSTATUS(status));
	}
	else if (WIFSIGNALED(status)) {
		printf("abnormal termination, signal number %d %s\n", WTERMSIG(status),
#ifdef	WCOREDUMP
			WCOREDUMP(status) ? "coredump generated" : "");
#else
		"");
#endif
	}
	else if (WIFSTOPPED(status)) {
		printf("child stopped, signal number %d\n", WSTOPSIG(status));
	}
}

int
main(int argc, char const *argv[])
{
	int status;

	if (0 > (status = my_system("date")))
		printf("system error\n");
	print_exit(status);

	if (0 > (status = my_system("nosuchcommand")))
		printf("system error\n");
	print_exit(status);

	if (0 > (status = my_system("who; exit 44")))
		printf("system error\n");
	print_exit(status);

	return 0;
}