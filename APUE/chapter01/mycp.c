#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static const int BUFFSIZE = 4096;

int
main(int argc, char const *argv[])
{
	int n;
	char buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
		if (n != write(STDOUT_FILENO, buf, n)) {
			printf("write error!\n");
			exit(-1);
		}
	}

	if (n < 0) {
		printf("read error!\n");
		exit(-1);
	}

	printf("total size %d\n", n);

	return 0;
}