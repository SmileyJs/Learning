#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

extern char **environ;

#define MAXSTGSIZE 2096

pthread_mutex_t envLock;

char envbuf[MAXSTGSIZE];

char *my_getenv(const char *name)
{
	size_t len = strlen(name);
	for (int i = 0; environ[i] != NULL; ++i) {
		if (0 == strncmp(name, environ[i], len) &&
			environ[i][len] == '=') {
			strncpy(envbuf, &environ[i][len+1], MAXSTGSIZE);
		}
	}

	return NULL;
}

static pthread_once_t init_once = PTHREAD_ONCE_INIT;

static void thread_init(void)
{
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	// in case of async signal call my_getenv_r
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);

	pthread_mutex_init(&envLock, &attr);

	pthread_mutexattr_destroy(&attr);
}

char *my_getenv_r(const char *name, char *buf)
{
	pthread_once(&init_once, thread_init);

	pthread_mutex_lock(&envLock);
	size_t len = strlen(name);
	for (int i = 0; environ[i] != NULL; ++i) {
		if (0 == strncmp(name, environ[i], len) &&
			environ[i][len] == '=') {
			strncpy(buf, &environ[i][len+1], MAXSTGSIZE);
		}
	}
	pthread_mutex_unlock(&envLock);
	return NULL;
}

static pthread_key_t key;

static void thread_key_init()
{
	pthread_mutex_init(&envLock, NULL);
	pthread_key_create(&key, free);
}

char *my_getenv_key(const char *name)
{
	pthread_once(&init_once, thread_key_init);

	char *envbuf;

	pthread_mutex_lock(&envLock);

	envbuf = pthread_getspecific(key);

	if (NULL == envbuf) {
		envbuf = (char*)malloc(MAXSTGSIZE);
		if (NULL == envbuf) {
			pthread_mutex_unlock(&envLock);
			return NULL;
		}
		pthread_setspecific(key, envbuf);
	}

	size_t len = strlen(name);
	for (int i = 0; environ[i] != NULL; ++i) {
		if (0 == strncmp(name, environ[i], len) &&
			environ[i][len] == '=') {
			strncpy(envbuf, &environ[i][len+1], MAXSTGSIZE);
		}
	}
	
	pthread_mutex_unlock(&envLock);
	return envbuf;
}

void *pthread_func(void *arg)
{
	int err;

	// my_getenv_key("USER");
	printf("==================\n");
	printf("%s %lu\n", my_getenv_key("USER"), pthread_self());

	pthread_exit(0);
}

int
main(int argc, char const *argv[])
{
	for (int i = 0; environ[i] != NULL; ++i) {
		printf("%s\n", environ[i]);
	}

	pthread_t tid;

	for (int i = 0; i != 100; ++i) {
		pthread_create(&tid, NULL, pthread_func, NULL);
	}

	sleep(1);

	return 0;
}