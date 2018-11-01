#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void charatatime(char *str)
{
	char *ptr;
	int c;

	setbuf(stdout, NULL);

	for (ptr = str; (c = *ptr++) != 0;)
		putc(c, stdout);
}

int
main(int argc, char const *argv[])
{
	pid_t pid;

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
	}
	else if (0 == pid) {
		charatatime("output child!\n");
		exit(0);
	}

	charatatime("output parent\n");

	return 0;
}