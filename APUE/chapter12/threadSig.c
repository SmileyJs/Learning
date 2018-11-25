#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>

static sigset_t mask;
static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int quitFlag;

void *thread_func(void *arg)
{
	int signo;

	while (1) {
		if (0 != sigwait(&mask, &signo)) {
			printf("sigwait failed!\n");
		}

		switch (signo) {
			case SIGINT:
				printf("SIGINT\n");
				break;
			case SIGQUIT:
				pthread_mutex_lock(&lock);
				quitFlag = 1;
				pthread_mutex_unlock(&lock);
				pthread_cond_signal(&cond);
				pthread_exit(0);
			default:
				printf("sig else\n");
		}
	}
}

int
main(int argc, char const *argv[])
{
	sigset_t oldMask;
	pthread_t tid;
	int err;

	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);
	sigaddset(&mask, SIGQUIT);

	if (0 != (err = pthread_sigmask(SIG_BLOCK, &mask, &oldMask))) {
		printf("pthread_sigmask err code %d\n", err);
	}

	if (0 != (err = pthread_create(&tid, NULL, thread_func, NULL))) {
		printf("pthread_create failed! %d\n", err);
	}

	pthread_mutex_lock(&lock);

	while (quitFlag == 0)
		pthread_cond_wait(&cond, &lock);

	pthread_mutex_unlock(&lock);

	quitFlag = 0;

	if (0 != (err = pthread_sigmask(SIG_SETMASK, &oldMask, NULL))) {
		printf("pthread_sigmask failed! end!\n");
	}

	return 0;
}