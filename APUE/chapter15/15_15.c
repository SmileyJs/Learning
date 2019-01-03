#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SHM_SIZE sizeof(long)
#define SHM_MODE 0600
#define NLOOP	10

int pfd1[2], pfd2[2];

void TELL_WAIT()
{
	if (-1 == pipe(pfd1)) {
		printf("%s pipe1 failed!\n", __FUNCTION__);
	}

	if (-1 == pipe(pfd2)) {
		printf("%s pipe2 failed!\n", __FUNCTION__);
	}
}

void WAIT_PARENT()
{
	printf("%s\n", __FUNCTION__);
	char c;

	if (-1 == read(pfd1[0], &c, 1)) {
		printf("%s read failed!\n", __FUNCTION__);
		return;
	}

	if (c != 'p')
		printf("%s invaild data!\n", __FUNCTION__);
}

void TELL_PARENT()
{
	printf("%s\n", __FUNCTION__);
	if (1 != write(pfd2[1], "c", 1)) {
		printf("%s write failed!\n", __FUNCTION__);
	}
}

void WAIT_CHILD()
{
	printf("%s\n", __FUNCTION__);
	char c;

	if (-1 == read(pfd2[0], &c, 1)) {
		printf("%s read failed!\n", __FUNCTION__);
	}

	if (c != 'c') {
		printf("%s invalid data\n", __FUNCTION__);
	}
}

void TELL_CHILD()
{
	printf("%s\n", __FUNCTION__);
	if (1 != write(pfd1[1], "p", 1)) {
		printf("%s write failed!\n", __FUNCTION__);
	}
}

static int update(long *p)
{
	return (*p)++;
}

int
main(int argc, char const *argv[])
{
	int shmId, counter;
	char *shmPtr;
	pid_t pid;

	if (-1 == (shmId = shmget(IPC_PRIVATE, SHM_SIZE, SHM_MODE))) {
		printf("shmget failed!\n");
		return -1;
	}

	if ((void*)-1 == (shmPtr = shmat(shmId, 0, 0))) {
		printf("shmat failed!\n");
		return -1;
	}

	sem_t *sem;
	sem_unlink("/haha"); // delete the old one.

	// TELL_WAIT();
	if (SEM_FAILED == (sem = sem_open("/haha", O_CREAT | O_EXCL, 0666, 0))) {
		printf("sem_open failed!\n");
		return -1;
	}


	if (0 > (pid = fork())) {
		printf("fork failed!\n");
		return -1;
	}
	else if (pid == 0) {
		printf("child process\n");
		for (int i = 0; i < NLOOP; i += 2) {
			
			if (i != (counter = update((long*)shmPtr))) {
				printf("child expect %d got %d\n", i, counter);
			}
			else {
				printf("child process %d\n", counter);
			}
			
			sem_post(sem);
			usleep(1); // to release cpu, to avoid execute continuously. 
			sem_wait(sem);

			// TELL_PARENT();
			// WAIT_PARENT();
		}
	}
	else {
		printf("parent process\n");
		for (int i = 1; i < NLOOP + 1; i += 2) {
			// WAIT_CHILD();
			sem_wait(sem);
			if (i != (counter = update((long*)shmPtr))) {
				printf("parent expect %d got %d\n", i, counter);
			}
			else {
				printf("parent process %d\n", counter);
			}

			sem_post(sem);
			usleep(1); // to release cpu, to avoid execute continuously. 
			// TELL_CHILD();
		}
	}

	if (-1 == shmctl(shmId, IPC_RMID, NULL)) {
		printf("shmdt failed!\n");
		return -1;
	}

	sem_close(sem);

	return 0;
}