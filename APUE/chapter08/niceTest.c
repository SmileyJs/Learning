#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>

unsigned long long count;
static struct timeval end;

void checktime(const char* s)
{
	struct timeval tv;

	if (0 > gettimeofday(&tv, NULL)) {
		printf("gettimeofday faield!\n");
	}

	if (tv.tv_sec > end.tv_sec && tv.tv_usec > end.tv_usec) {
		printf("%s count = %llu\n", s, count);
		exit(0);
	}

}

int
main(int argc, char const *argv[])
{
	printf("%d\n", nice(0));

	if (argc != 2) {
		printf("argument error!\n");
		return -1;
	}

	int pid = 0;
	int adj = 0;
	char *s;
	int ret;

	setbuf(stdout, NULL);

	int nzero = sysconf(_SC_NZERO);
	printf("default nzero = %d\n", nzero);

	adj = atoi(argv[1]);

	if (0 > gettimeofday(&end, NULL)) {
		printf("gettimeofday failed! %s\n", strerror(errno));
	}

	end.tv_sec += 10;

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
		return -1;
	}
	else if (pid == 0) {
		s = "child";
		printf("current nice value in child is %d, adjusting by %d\n", nice(0), adj);
		errno = 0;

		if (-1 == (ret = nice(adj)) && errno != 0)
			printf("set priority failed\n");
		printf("new priority is %d\n", ret);
	}
	else {
		s = "parent";
		printf("current nice value in parent is %d\n", nice(0));
	}

	while (1) {
		if (++count == 0) {
			printf("count wrap\n");
			break;
		}
		checktime(s);
	}

	return 0;
}