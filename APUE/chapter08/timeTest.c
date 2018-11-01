#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

void print_time(time_t real, struct tms *start, struct tms *end)
{
	long clkcnt = 0;

	clkcnt = sysconf(_SC_CLK_TCK);

	printf("clkcnt = %ld\n", clkcnt);

	printf("real time = %ld\n", real/clkcnt);
	printf("user time = %ld\n", (end->tms_utime - start->tms_utime)/clkcnt);
	printf("system time = %ld\n", (end->tms_stime - start->tms_stime)/clkcnt);
	printf("child user time = %ld\n", (end->tms_cutime - start->tms_cutime)/clkcnt);
	printf("child system time = %ld\n", (end->tms_cstime - start->tms_cstime)/clkcnt);
}

int do_cmd(const char *cmd)
{
	struct tms startTv, endTv;
	clock_t start, end;
	int status;

	if (-1 == (start = times(&startTv)))
		printf("time failed!\n");

	if (0 > (status = system(cmd)))
		printf("system failed!\n");

	if (-1 == (end = times(&endTv)))
		printf("time failed!\n");

	print_time(end-start, &startTv, &endTv);

	return status;
}

int
main(int argc, char const *argv[])
{
	setbuf(stdout, NULL);

	for (int i = 1; i != argc; ++i)
		do_cmd(argv[i]);

	return 0;
}