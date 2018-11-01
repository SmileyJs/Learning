#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int
main(int argc, char const *argv[])
{
	char buf[128] = {0};

	printf("%s\n", buf);

	int ret = -1;
	snprintf(buf, sizeof(buf), "pidof %s >> /dev/null", "testCount");
	ret = system(buf);

	printf("ret is %d\n", ret);

	if (!WEXITSTATUS(ret)) {
		printf("is running\n");
	}
	else {
		printf("process don't exist\n");
	}

	return 0;
}