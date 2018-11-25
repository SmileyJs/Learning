#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

static int var;

const static unsigned int ThreadNum = 8;
static pthread_barrier_t b;
static pthread_mutex_t lock;


static void *thread_func(void *arg)
{
	pthread_mutex_lock(&lock);
	var++;
	pthread_mutex_unlock(&lock);

	sleep(2);

	int ret = pthread_barrier_wait(&b);
	printf("return value:%d\n", ret);

	printf("thread_func end %lu\n", pthread_self());

	pthread_exit(0);
}

int
main(int argc, char const *argv[])
{
	pthread_t tid;
	int err;
	
	pthread_mutex_init(&lock, NULL);
	pthread_barrier_init(&b, NULL, ThreadNum + 1);

	for (int i = 0; i != ThreadNum; ++i) {
		if (0 != (err = pthread_create(&tid, NULL, thread_func, NULL))) {
			printf("pthread_create failed! err code %d\n", err);
		}
	}

	pthread_barrier_wait(&b);

	printf("last value is %d\n", var);

	// if count was set as ThreadNum without +1, the process will block here.	
	err = pthread_barrier_destroy(&b);

	printf("end %d\n", err);

	pthread_mutex_destroy(&lock);
	
	return 0;
}