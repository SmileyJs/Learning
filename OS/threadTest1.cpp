#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int sum;
void *runner(void *param);

int
main(int argc, char *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;

	if (argc != 2) {
		printf("argument num error!\n");
		return -1;
	}

	if (atoi(argv[1]) < 0) {
		printf("argument must > 0!\n");
		return -1;
	}

	pthread_attr_init(&attr);

	pthread_create(&tid, &attr, runner, NULL);

	pthread_join(tid, NULL);

	printf("sum is %d\n", sum);

	return 0;
}

void *runner(void *param)
{
	int i, upper = 5;
	sum = 0;

	for (i = 1; i <= upper; ++i) {
		sum += i;
	}

	pthread_exit(0);
}