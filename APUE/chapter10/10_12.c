#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

#define SIZE 1024*1024

void
sig_alrm(int signo)
{
	printf("%s\n", __FUNCTION__);
}

int
main(int argc, char const *argv[])
{
	if (signal(SIGALRM, sig_alrm)) {
		printf("signal failed!\n");
	}

	char buf[SIZE] = {0};

	for (int i = 0; i != SIZE - 1; ++i) {
		buf[i] = 'J';
	}

	buf[SIZE-1] = '\0';

	FILE *fp;
	int n;

	if (NULL == (fp = fopen("./tmp", "w+"))) {
		printf("fopen failed!\n");
	}

	alarm(2);
	n = fwrite(buf, 1, SIZE, fp);

	if (n != SIZE)
		printf("wirte failed!\n");

	printf("%s\n", buf);

	return 0;
}