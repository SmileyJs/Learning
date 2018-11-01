#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

#define doit(name) pr_limit(#name, name)

void
pr_limit(char *name, int res)
{
	printf("%s\n", __FUNCTION__);

	struct rlimit limit;
	unsigned long long lim;

	if (-1 == getrlimit(res, &limit)) {
		printf("getrlimit failed!\n");
	}

	printf("%s ", name);

	if (limit.rlim_cur == RLIM_INFINITY) {
		printf("infinity ");
	}
	else {
		lim = limit.rlim_cur;
		printf("%llu ", lim);
	}

	if (limit.rlim_max == RLIM_INFINITY) {
		printf("infinity\n");
	}
	else {
		lim = limit.rlim_max;
		printf("%llu\n", lim);
	}
}

int
main(int argc, char const *argv[])
{
	doit(RLIMIT_NICE);

	return 0;
}