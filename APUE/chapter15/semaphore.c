#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>

int
main(int argc, char const *argv[])
{
	int semid;
	pid_t pid;
	struct sembuf sb;

	if (-1 == (semid = semget(IPC_PRIVATE, 1, IPC_EXCL | IPC_CREAT | 0666))) {
		printf("semget error! %s\n", strerror(errno));
		return -1;
	}

	int val = 1;

	if (-1 == semctl(semid, 0, SETVAL, val)) {
		printf("semctl failed! %s\n", strerror(errno));
		return -1;
	}

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
		return -1;
	}
	else if (0 == pid) {
		printf("child process\n");

		sb.sem_num = 0;
		sb.sem_op = -1;

		if (-1 == semop(semid, &sb, 1)) {
			printf("sem_op get failed! %s\n", strerror(errno));
			return -1;
		}

		printf("child get\n");
		sleep(5);

		sb.sem_op = 1;
		if (-1 == semop(semid, &sb, 1)) {
			printf("sem_op release failed! %s\n", strerror(errno));
			return -1;
		}

		printf("child release\n");
	}
	else {
		printf("parent process\n");

		sb.sem_num = 0;
		sb.sem_op = -1;

		if (-1 == semop(semid, &sb, 1)) {
			printf("sem_op get failed! %s\n", strerror(errno));
			return -1;
		}

		printf("parent get\n");
		sleep(5);

		sb.sem_op = 1;
		if (-1 == semop(semid, &sb, 1)) {
			printf("sem_op release failed! %s\n", strerror(errno));
			return -1;
		}
		printf("parent release\n");

		sleep(5);
	}

	return 0;
}