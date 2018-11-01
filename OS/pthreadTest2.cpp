#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;

static int cnt = 0;

void* test1(void *arg)
{
	printf("test1\n");

	for (int i = 0; i < 10; ++i) {
		if (0 != pthread_mutex_trylock(&mutex))
			continue;
		printf("%d\n", cnt++);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}

	pthread_exit(0);
}

void* test2(void *arg)
{
	printf("test2\n");

	for (int i = 0; i < 10; ++i) {
		pthread_mutex_lock(&mutex);
		printf("%d\n", cnt++);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}

	pthread_exit(0);
}

int
main(int argc, char const *argv[])
{
	pthread_t pid1, pid2;

	pthread_create(&pid1, NULL, test1, NULL);
	pthread_create(&pid2, NULL, test2, NULL);
	pthread_mutex_init(&mutex, NULL);

	pthread_join(pid1, NULL);
	pthread_join(pid2, NULL);
	pthread_mutex_destroy(&mutex);

	printf("game over %d\n", cnt);

	return 0;
}