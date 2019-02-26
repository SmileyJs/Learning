#include <stdio.h>
#include <stdlib.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define QUEUE_NUM	3

#define KEY 0x123
#define MSG_SIZE	32

struct myMsg {
	long mType;
	char mText[MSG_SIZE];
};

struct threadInfo {
	int qid;
	int fd;
};

void *
helper(void *arg)
{
	struct threadInfo *tip  = arg;
	struct myMsg msg;
	int n;

	while (1) {
		memset(&msg, 0, sizeof(struct myMsg));

		if (-1 == (n = msgrcv(tip->qid, &msg, MSG_SIZE, 0, MSG_NOERROR))) {
			printf("msgrcv failed! %s\n", strerror(errno));
			exit(-1);
		}

		if (-1 == write(tip->fd, msg.mText, n)) {
			printf("write failed! %s\n", strerror(errno));
			exit(-1);
		}
	}

	return NULL;
}

int
main(int argc, char const *argv[])
{
	struct pollfd pfd[QUEUE_NUM];
	struct threadInfo ti[QUEUE_NUM];
	int err;
	int fd[2];
	int qid[QUEUE_NUM];
	pthread_t tid[QUEUE_NUM];
	int n;
	char buf[MSG_SIZE];

	for (int i = 0; i != QUEUE_NUM; ++i) {
		if (-1 == (err = socketpair(AF_UNIX, SOCK_DGRAM, 0, fd))) {
			printf("socketpair failed! %s\n", strerror(errno));
			return -1;
		}
		
		if (-1 == (qid[i] = msgget(KEY+i, IPC_CREAT | 0666))) {
			printf("msgget failed! %s\n", strerror(errno));
			return -1;
		}

		pfd[i].fd = fd[0];
		pfd[i].events = POLLIN;

		ti[i].fd = fd[1];
		ti[i].qid = qid[i];

		printf("Queue id %d is %d\n", i, qid[i]);

		if (0 != (err = pthread_create(&tid[i], NULL, helper, &ti[i]))) {
			printf("pthread_create failed! %s\n", strerror(errno));
			return -1;
		}
	}


	while (1) {
		if (-1 == poll(pfd, QUEUE_NUM, -1)) {
			printf("poll failed! %s\n", strerror(errno));
			return -1;
		}

		for (int i = 0; i != QUEUE_NUM; ++i) {
			if (pfd[i].events & POLLIN) {
				if (0 > (n = read(pfd[i].fd, buf, MSG_SIZE))) {
					printf("read failed! %s\n", strerror(errno));
					return -1;
				}

				buf[n] = 0;
				printf("queue id %d receive %s\n", qid[i], buf);
			}
		}
	}

	return 0;
}