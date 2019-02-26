#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>

#define MSG_SIZE	32

struct myMsg {
	long mType;
	char mText[MSG_SIZE];
};

int
main(int argc, char const *argv[])
{
	if (argc != 3) {
		printf("argument faield!\n");
		return -1;
	}

	struct myMsg m;
	key_t key;
	int qid;

	key = strtol(argv[1], NULL, 0);

	printf("key is %d\n", key);

	if (-1 == (qid = msgget(key, IPC_CREAT | 0666))) {
		printf("msgget faield %s\n", strerror(errno));
		return -1;
	}

	memset(&m.mText, 0, MSG_SIZE);
	strncpy(m.mText, argv[2], MSG_SIZE - 1);
	m.mType = 1;

	if (-1 == msgsnd(qid, &m, strlen(m.mText), 0)) {
		printf("msgsnd failed! %s\n", strerror(errno));
	}

	return 0;
}