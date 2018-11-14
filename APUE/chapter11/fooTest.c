#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NHASH 29
#define HASH(id)	(((unsigned long)id) % NHASH)

struct Foo {
	int count;
	pthread_mutex_t lock;
	int id;
	struct Foo *next;
	void *data;
};

struct Foo *fh[NHASH];

pthread_mutex_t hashLock = PTHREAD_MUTEX_INITIALIZER;

struct Foo *
Foo_alloc(int id)
{
	struct Foo* fp;
	int index;

	if (NULL != (fp = malloc(sizeof(struct Foo)))) {
		fp->count = 1;
		fp->id= id;

		if (0 != pthread_mutex_init(&fp->lock, NULL)) {
			free(fp);
			fp = NULL;
		}

		pthread_mutex_lock(&hashLock);
		index = HASH(id);
		fp->next = fh[index];
		fh[index] = fp;
		pthread_mutex_lock(&fp->lock);
		pthread_mutex_unlock(&hashLock);
		fp->data = NULL;
		pthread_mutex_unlock(&fp->lock);
	}

	return fp;
}

void
Foo_rele(struct Foo *fp)
{
	struct Foo *tmp;
	int index;

	pthread_mutex_lock(&fp->lock);
	if (fp->count == 1) {
		pthread_mutex_unlock(&fp->lock);
		pthread_mutex_lock(&hashLock);
		pthread_mutex_lock(&fp->lock);
		if (fp->count != 1) {
			fp->count--;
			pthread_mutex_unlock(&fp->lock);
			pthread_mutex_unlock(&hashLock);
			return;	
		}

		index = HASH(fp->id);
		tmp = fh[index];
		if (tmp == fp) {
			fh[index] = fp->next;
		}
		else {
			while (tmp->next != fp) {
				tmp = tmp->next;
			}
			tmp->next = fp->next;
		}

		pthread_mutex_unlock(&fp->lock);
		pthread_mutex_destroy(&fp->lock);
		pthread_mutex_unlock(&hashLock);
		free(fp);
	}
	else {
		fp->count--;
		pthread_mutex_unlock(&fp->lock);
	}
}

void
Foo_hold(struct Foo *fp)
{
	pthread_mutex_lock(&fp->lock);
	fp->count++;
	pthread_mutex_unlock(&fp->lock);
}

struct Foo *
Foo_find(int id)
{
	struct Foo *fp;
	pthread_mutex_lock(&hashLock);
	for (fp = fh[HASH(id)]; fp != NULL; fp = fp->next) {
		if (fp->id == id) {
			Foo_hold(fp);
			break;
		}

	}

	pthread_mutex_unlock(&hashLock);
	return fp;
}

int
main(int argc, char const *argv[])
{
	
	return 0;
}