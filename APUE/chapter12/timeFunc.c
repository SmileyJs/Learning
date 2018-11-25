#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct func_info {
	void *(*to_func)(void *);
	void *to_arg;
	struct timespec to_wait;
} FuncInfo;

static int count;

void
gettime(struct timespec *tsp)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);

	tsp->tv_sec = tv.tv_sec;
	tsp->tv_nsec = tv.tv_usec * 1000;
}

int
make_thread(void *(*func)(void *), void *arg)
{
	pthread_t tid;
	pthread_attr_t attr;
	int err;

	err = pthread_attr_init(&attr);
	if (0 != err) {
		printf("pthread_attr_init failed!\n");
		return err;
	}

	err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if (0 != err) {
		printf("pthread_attr_setdetachstate failed!\n");
		return err;
	}

	err = pthread_create(&tid, &attr, func, arg);
	if (0 != err) {
		printf("pthread_create failed\n");
	}

	return err;
}

void *
timeout_helper(void *arg)
{
	FuncInfo *info = (FuncInfo *)arg;

	clock_nanosleep(CLOCK_REALTIME, 0, &info->to_wait, NULL);
	(*info->to_func)(info->to_arg);
	free(info);

	return 0;
}

void
timeout(struct timespec *when, void *(*func)(void*))
{
	struct timespec now;
	FuncInfo *info;

	gettime(&now);

	if (when->tv_sec > now.tv_sec ||
		(when->tv_sec == now.tv_sec && when->tv_nsec > now.tv_nsec)) {
		info = malloc(sizeof(FuncInfo));
		if (info != NULL) {
			info->to_func = func;
			info->to_arg = NULL;
			info->to_wait.tv_sec = when->tv_sec - now.tv_sec;
			if (when->tv_nsec > now.tv_nsec) {
				info->to_wait.tv_nsec = when->tv_nsec - now.tv_nsec;
			}
			else {
				info->to_wait.tv_nsec = when->tv_nsec - now.tv_nsec + 1000000;
				info->to_wait.tv_sec --;
			}
		}

		int err = make_thread(timeout_helper, (void*) info);

		if (0 != err)
			printf("make_thread failed!\n");
		return;
	}


	(*func)(0);
}

void*
thread_func(void *arg)
{
	printf("%lu count = %d\n", pthread_self(), ++count);
	
	pthread_exit(0);
}

int
main(int argc, char const *argv[])
{
	int arg = 1;

	struct timespec tsp;
	gettime(&tsp);

	for (int i = 1; i != 10; ++i) {
		tsp.tv_sec += i;
		timeout(&tsp, thread_func);
	}

	while (1) {
		printf("count = %d\n", count);
		sleep(1);
	}

	return 0;
}