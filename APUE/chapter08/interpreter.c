#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int
main(int argc, char const *argv[])
{
	pid_t pid;

	if (0 > (pid = fork())) {
		printf("fork failed! %s\n", strerror(errno));
		return -1;
	}
	else if (pid == 0) {
		if (-1 == execl("/home/wangjieshuai/JS/Practise/APUE/chapter08/interTest", "interTest", "arg1", "arg2", (char*)0)) 
			printf("execl failed! %s\n", strerror(errno));
		exit(0);
	}

	if (-1 == waitpid(pid, NULL, 0))
		printf("waitpid failed %s\n", strerror(errno));

	return 0;
}