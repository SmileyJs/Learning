#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int
main(int argc, char const *argv[])
{
	sem_t *sem;

	sem_unlink("/haha");

	if (SEM_FAILED == (sem = sem_open("/haha", O_CREAT | O_EXCL, 0666, 1))) {
		printf("sem_opem failed! %s\n", strerror(errno));
		return -1;
	}

	// need share memory
	// if (-1 == sem_init(&sem, 1, 1)) {
	// 	printf("sem_init failed!\n");
	// 	return -1;
	// }

	pid_t pid;

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
	}
	else if (0 == pid) {
		printf("child process\n");
		sem_wait(sem);
		printf("child get semaphore\n");
		sleep(5);
		sem_post(sem);
		printf("child release semaphore\n");
	}
	else {
		printf("parent process\n");
		sem_wait(sem);
		printf("parent get semaphore\n");
		sleep(5);
		sem_post(sem);
		printf("parent release semaphore\n");
	}

	sem_close(sem);
	// sem_destroy(sem);

	return 0;
}