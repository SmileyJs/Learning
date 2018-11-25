#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lockA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lockB = PTHREAD_MUTEX_INITIALIZER;

void prepare(void)
{
	printf("%s\n", __FUNCTION__);

	pthread_mutex_lock(&lockA);
	pthread_mutex_lock(&lockB);
}

void parent(void)
{
	printf("%s\n", __FUNCTION__);

	pthread_mutex_unlock(&lockA);
	pthread_mutex_unlock(&lockB);
}

void child(void)
{
	printf("%s\n", __FUNCTION__);

	pthread_mutex_unlock(&lockA);
	pthread_mutex_unlock(&lockB);
}

int
main(int argc, char const *argv[])
{
	if (0 != pthread_atfork(prepare, parent, child)) {
		printf("pthread_atfork faield!\n");
	}

	pid_t pid;

	printf("start fork\n");

	fflush(stdout); // 12-1

	if (0 > (pid = fork())) {
		printf("fork faield!\n");
	}
	else if (0 == pid) {
		printf("child return\n");
	}
	else {
		printf("parent return\n");
	}

	return 0;
}