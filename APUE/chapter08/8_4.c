#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void
charactatime(char *s)
{
	char *p;
	setbuf(stdout, NULL);

	for (p = s; *p != 0; ++p)
		putc(*p, stdout);
}

int
main(int argc, char const *argv[])
{
	pid_t pid;

	setbuf(stdout, NULL);

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
	}
	else if (0 == pid) {
		charactatime("output from child!\n");
	}
	else {
		waitpid(pid, NULL, 0);
		charactatime("output from parent\n");
	}

	return 0;
}