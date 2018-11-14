#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

int
main(int argc, char const *argv[])
{
	int err;
	pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	struct timespec tp;
	char buf[64] = {0};
	struct tm *tmp;

	pthread_mutex_lock(&lock);
	printf("locked\n");

	clock_gettime(CLOCK_REALTIME, &tp);
	tmp = localtime(&tp.tv_sec);
	strftime(buf, sizeof(buf), "%r", tmp);
	printf("current time is %s\n", buf);

	tp.tv_sec += 10;

	err = pthread_mutex_timedlock(&lock, &tp);

	clock_gettime(CLOCK_REALTIME, &tp);
	tmp = localtime(&tp.tv_sec);
	strftime(buf, sizeof(buf), "%r", tmp);
	printf("current time is %s\n", buf);	

	if (0 == err) {
		printf("lock again\n");
	}
	else {
		printf("time out %s\n", strerror(err));
	}

	return 0;
}