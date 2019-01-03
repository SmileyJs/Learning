#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

struct msgbuf {
	long mType;
	char mText[32];
};

int
main(int argc, char const *argv[])
{
	pid_t pid;

	int msgId = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
	if (-1 == msgId) {
		printf("msgget failed!\n");
		return -1;
	}

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
		return -1;
	}
	else if (0 == pid) {
		struct msgbuf msg;
		msg.mType = 1;
		sprintf(msg.mText, "%s", "hello kity!");
		while (1) {
			if (-1 == msgsnd(msgId, &msg, sizeof(msg.mText), 0)) {
				printf("msgsnd failed! %s\n", strerror(errno));
				exit(-1);
			}
			sleep(1);
		}
	}
	else {
		struct msgbuf msg;
		while (1) {
			if (-1 == msgrcv(msgId, &msg, sizeof(msg.mText), 0, 0)) {
				printf("msgrcv failed! %s\n", strerror(errno));
				exit(-1);
			}
			printf("receive msg mType[%ld] content[%s]\n", msg.mType, msg.mText);
		}
	}

	return 0;
}