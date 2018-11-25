#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int
make_thread(void* (*func)(void *), void *arg)
{
	pthread_t tid;
	pthread_attr_t attr;
	int err;

	if (0 != (err = pthread_attr_init(&attr))) {
		printf("pthread_attr_init faield! err %d\n", err);
		return err;
	}

	if (0 != (err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED))) {
		printf("pthread_attr_setdetachstate failed! err %d\n", err);
		return err;
	}

	if (0 != (err = pthread_create(&tid, &attr, func, arg))) {
		printf("pthread_create faield! err %d\n", err);
		return err;
	}

	size_t stackSize;
	void *stackAddr;

	pthread_attr_getstack(&attr, &stackAddr, &stackSize);

	printf("address 0x%p size %zu\n", stackAddr, stackSize);

	pthread_attr_destroy(&attr);
	return err;
}

void *pthread_func(void *arg)
{
	printf("%s task id %lu\n", __FUNCTION__, pthread_self());

	sleep(1);

	pthread_exit(0);
}

int
main(int argc, char const *argv[])
{
	make_thread(pthread_func, NULL);

	return 0;
}