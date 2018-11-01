#include <iostream>

#include <stdio.h>	
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int cnt = 0;

pthread_mutex_t mutex1;

void* thread1(void* param)
{
	printf("%s\n", "thread1 start");

	for (int i = 0; i < 5; ++i) {
		pthread_mutex_lock(&mutex1);
		int val = ++cnt;
		printf("thread1 the %d time, start %d\n", i, cnt);
		sleep(1);
		printf("thread1 the %d time, end %d\n", i, cnt);
		cnt = val;	
		pthread_mutex_unlock(&mutex1);
	}

	printf("%s\n", "thread1 end");
	pthread_exit(0);
}

void* thread2(void *param)
{
	printf("%s\n", "thread2 start");

	for (int i = 0; i < 5; ++i) {
		pthread_mutex_lock(&mutex1);
		int val = ++cnt;
		sleep(2);
		printf("thread2 the %d time, end %d\n", i, cnt);
		cnt = val;
		pthread_mutex_unlock(&mutex1);
	}

	printf("%s\n", "thread2 end");
	pthread_exit(0);
}

int
main(int argc, char const *argv[])
{
	pthread_t tid1, tid2;

	pthread_mutex_init(&mutex1, NULL);
	pthread_create(&tid1, NULL, thread1, NULL);
	pthread_create(&tid2, NULL, thread2, NULL);
	
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&mutex1);

	printf("count value is %d\n", cnt);

	return 0;
}