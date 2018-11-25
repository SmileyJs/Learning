#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct _job {
	struct _job *prev;
	struct _job *next;
	pthread_t id;
} Job;

typedef struct _queue {
	Job *head;
	Job *tail;
	pthread_rwlock_t lock;
} Queue;

int
queue_init(Queue *q)
{
	int err;

	q->head = NULL;
	q->tail = NULL;

	err = pthread_rwlock_init(&q->lock, NULL);

	if (0 != err)
	{
		printf("pthread_rwlock_init failed!\n");
		return -1;
	}

	return 0;
}

void
queue_insert(Queue *q, Job *j)
{
	pthread_rwlock_wrlock(&q->lock);

	j->prev = NULL;
	j->next = q->head;

	if (NULL != q->head) {
		q->head->prev = j;
	}
	else {
		q->tail = j;
	}
	q->head = j;

	pthread_rwlock_unlock(&q->lock);
}

void
queue_append(Queue *q, Job *j)
{
	pthread_rwlock_wrlock(&q->lock);

	j->next = NULL;
	j->prev = q->tail;

	if (NULL != q->tail) {
		q->tail->next = j;
	}
	else {
		q->head = j;
	}
	q->tail = j;

	pthread_rwlock_unlock(&q->lock);
}

void
remove_job(Queue *q, Job *j)
{
	pthread_rwlock_wrlock(&q->lock);

	if (j == q->head) {
		q->head = j->next;
		if (q->tail == j) {
			q->tail = NULL;
		}
		else {
			j->next->prev = j->prev;
		}
	}
	else if (j == q->tail) {
		q->tail = j->prev;
		j->prev->next = j->next;
	}
	else {
		j->prev->next = j->next;
		j->next->prev = j->prev;
	}

	pthread_rwlock_unlock(&q->lock);
}

Job *
find_job(Queue *q, pthread_t id)
{
	pthread_rwlock_rdlock(&q->lock);

	Job *j = q->head;

	while (j) {
		if (j->id == id)
			break;
		j = j->next;
	}

	pthread_rwlock_unlock(&q->lock);

	return j;
}

void
queue_destroy(Queue *q)
{
	while (q->head) {
		remove_job(q, q->head);
	}
}

static void *pthread1(void *arg)
{
	long unsigned int tid = pthread_self();
	printf("%s %lu\n", __FUNCTION__, tid);

	while (1) {
		Queue *q = (Queue*)arg;

		Job* j = find_job(q, tid);

		if (j) {
			printf("%s get task j->id %lu\n", __FUNCTION__, j->id);
		}
		usleep(100000);
	}
}

static void *pthread2(void *arg)
{
	long unsigned int tid = pthread_self();
	printf("%s %lu\n", __FUNCTION__, tid);

	while (1) {
		Queue *q  = (Queue*)arg;

		Job* j = find_job(q, tid);

		if (j) {
			printf("%s get task j->id %lu\n", __FUNCTION__, j->id);
		}
		usleep(100000);
	}
}

int
main(int argc, char const *argv[])
{
	Queue queue;

	if (0 != queue_init(&queue)) {
		printf("queue_init failed!\n");
		return -1;
	}

	pthread_t tid1, tid2;
	int err;

	if (0 != (err = pthread_create(&tid1, NULL, pthread1, (void*)&queue))) {
		printf("pthread_create failed err %d!\n", err);
	}

	if (0 != (err = pthread_create(&tid2, NULL, pthread2, (void*)&queue))) {
		printf("pthread_create failed err %d\n", err);
	}

	while (1) {

		Job j;
		j.prev = NULL;
		j.next = NULL;

		long int ran = random();
		j.id = ran %2 ? tid1 : tid2;

		if (ran % 2) {
			queue_append(&queue, &j);
		}
		else {
			queue_insert(&queue, &j);
		}

		usleep(10000);
	}

	queue_destroy(&queue);

	return 0;
}