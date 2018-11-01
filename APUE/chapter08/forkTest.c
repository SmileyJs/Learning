#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int glovar = 6;
char buf[] = "string write to file!\n";

int
main(int argc, char const *argv[])
{
	int var = 88;

	pid_t pid;

	if (-1 == write(STDOUT_FILENO, buf, strlen(buf)))
		printf("write failed %s\n", strerror(errno));

	printf("hello world!\n");

	if ((pid = vfork()) < 0) {
		printf("fork failed! %s\n", strerror(errno));
	}
	else if (pid == 0) {
		glovar++;
		var++;
		// fclose(stdout);
		exit(0);
	}
	else {
		// sleep(2);
	}

	printf("pid = %d, glovar = %d, var = %d\n", getpid(), glovar, var);

	return 0;
}