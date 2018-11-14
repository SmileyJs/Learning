#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void cleanUp(void *arg)
{
	printf("cleanUp %s\n", (char*)arg);
}

void *thr1_func(void *arg)
{
	printf("%s\n", __FUNCTION__);

	pthread_cleanup_push(cleanUp, "thread1 first handler");
	pthread_cleanup_push(cleanUp, "thread1 second handler");

	printf("thread1 push complete\n");

	if (arg)
		return (void*)1;

	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);

	return (void*)1;
}

void *thr2_func(void *arg)
{
	printf("%s\n", __FUNCTION__);

	pthread_cleanup_push(cleanUp, "thread2 first handler");
	pthread_cleanup_push(cleanUp, "thread2 second hdndler");

	printf("thread2 push complete\n");

	if (arg)
		pthread_exit((void*)2);

	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);

	pthread_exit((void*)2); 
}

int
main(int argc, char const *argv[])
{
	int err;
	pthread_t tid1, tid2;
	void *tRet;

	if (0 != (err = pthread_create(&tid1, NULL, thr1_func, (void*)1))) {
		printf("pthread_create thread1 failed! %d\n", err);
	}

	if (0 != (err = pthread_create(&tid2, NULL, thr2_func, (void*)1))) {
		printf("pthread_create thread2 failed! %d\n", err);
	}

	if (0 != (err = pthread_join(tid1, &tRet))) {
		printf("pthread_join 1 faield!\n");
	}

	printf("thread1 return value %d\n", (int)tRet);

	if (0 != (err = pthread_join(tid2, &tRet))) {
		printf("pthread_join 2 failed!\n");
	}

	printf("thread2 return value %d\n", (int)tRet);

	return 0;
}