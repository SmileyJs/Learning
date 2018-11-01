#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


void *sum(void* n)
{
	int ret = 0;
	for (int i = 1; i <= *(int*)n; ++i) {
		ret += i;
	}

	std::cout << "sum: " << ret << std::endl;
	pthread_exit((void*)&ret);
}

int
main(int argc, char const *argv[])
{
	if (2 != argc) {
		std::cout << "argument error!" << std::endl;
		return -1;
	}

	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int *result;
	int arg = atoi(argv[1]);

	std::cout << "arg is " << arg << std::endl;

	int err;

	err = pthread_create(&tid, &attr, sum, (void*)&arg);
	if (0 != err) {
		std::cout << "pthread create error!" << std::endl;
		return -1;
	}

	err = pthread_join(tid, (void**)&result);
	if (0 != err) {
		std::cout << "pthread join error!" << std::endl;
		return -1;
	}

    // ??
	std::cout << "the sum is " << *result << std::endl;

	return 0;
}

