#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

#define MAXLINESIZE 1024

extern char **environ;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void
show_env()
{
	for (int i = 0; environ[i] != NULL; ++i) {
		printf("%s\n", environ[i]);
	}
}

void
putenv_r(char *str)
{
	if (NULL == str) {
		printf("parament is null\n");
		return;
	}

	printf("%s\n", __FUNCTION__);

	sigset_t newset, oldset;

	sigfillset(&newset);

	if (0 != sigprocmask(SIG_SETMASK, &newset, &oldset)) {
		printf("sigprocmask failed\n");
	}

	pthread_mutex_lock(&lock);

	putenv(str);

	pthread_mutex_unlock(&lock);

	if (0 != sigprocmask(SIG_SETMASK, &oldset, NULL)) {
		printf("sigprocmask end faield!\n");
	}

	show_env();
}

int
main(int argc, char const *argv[])
{

	if (0 != putenv("TEST=11111")) {
		printf("putenv failed! %s\n", strerror(errno));
	}

	putenv_r("TEST=222222");

	return 0;
}