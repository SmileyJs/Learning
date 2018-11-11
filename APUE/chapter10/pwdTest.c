#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

static void my_alarm(int arg)
{
	struct passwd *rootPtr;

	printf("in signal handler\n");

	if (NULL == (rootPtr = getpwnam("root")))
		printf("getpwnam failed!\n");

	alarm(1);
}

int
main(int argc, char const *argv[])
{
	struct passwd *ptr;

	signal(SIGALRM, my_alarm);

	alarm(1);

	while (1) {
		if (NULL == (ptr = getpwnam("wjs")))
			printf("getpwnam failed %s\n", strerror(errno));

		// printf("%s\n", ptr->pw_name);

		if (strcmp(ptr->pw_name, "wjs") != 0)
			printf("return value corrupted pw_name = %s\n", ptr->pw_name);
	}

	return 0;
}