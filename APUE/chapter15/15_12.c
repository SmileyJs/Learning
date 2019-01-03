#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>

typedef struct msgbuf {
	int mType;
	int mData;
} MsgBuf;

int
main(int argc, char const *argv[])
{
	
	for (int i = 0; i != 5; ++i) {
		int msgid = msgget(IPC_PRIVATE, 0666);
		printf("%d\n", msgid);
		msgctl(msgid, IPC_RMID, NULL);
	}

	for (int i = 0; i != 5; ++i) {
		int msgid = msgget(IPC_PRIVATE, 0666);
		printf("%d\n", msgid);

		MsgBuf buf;
		buf.mType = 1;
		buf.mData = 2;

		if (-1 == msgsnd(msgid, (void*)&buf, sizeof(buf.mData), IPC_NOWAIT)) {
			printf("msgsnd failed!\n");
			return -1;
		}
	}

	return 0;
}