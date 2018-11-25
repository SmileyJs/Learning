#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define PRINTTID printf("%s pid = %d, tid = %lu\n", __FUNCTION__, getpid(), pthread_self())

struct A {
	int a;
	int b;
	int c;
	int d;
};

void printStruct(const char *s, struct A *t)
{
	printf("%s\n", s);
	printf("a = %d\n", t->a);
	printf("b = %d\n", t->b);
	printf("c = %d\n", t->c);
	printf("d = %d\n", t->d);
}	

void *thr1_func(void *arg)
{
	PRINTTID;

	struct A *tmp = (struct A *)malloc(sizeof(struct A));
	tmp->a = 1;
	tmp->b = 2;
	tmp->c = 3;
	tmp->d = 4;

	printStruct("thread1", tmp);

	pthread_exit((void*)tmp);
}

void *thr2_func(void *arg)
{
	PRINTTID;

	pthread_exit(0);
}

int
main(int argc, char const *argv[])
{
	pthread_t tid1, tid2;
	int err;

	PRINTTID;

	if (0 != (err = pthread_create(&tid1, NULL, thr1_func, NULL))) {
		printf("pthread_create failed! errcode: %d\n", err);
	}

	struct A *t;

	pthread_join(tid1, (void*)&t);

	if (0 != (err = pthread_create(&tid2, NULL, thr2_func, NULL))) {
		printf("pthread_create failed! errcode: %d\n", err);
	}

	pthread_join(tid2, NULL);

	printStruct("main", (struct A*)t);
	free(t);

	return 0;
}