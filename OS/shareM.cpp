#include <iostream>

#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <sys/shm.h>
#include <sys/ipc.h>

int
main(int argc, char const *argv[])
{
	pid_t pid;
	pid = fork();

	key_t key = 111;
	void *shm = NULL;

	if (-1 == pid) {
		std::cout << "create new process error!" << std::endl;
		return -1;
	}
	else if (0 == pid) {
		std::cout << "this is child process!" << std::endl;
	
		int shmid = shmget(key, 10, 0666 | IPC_CREAT);
		shm = shmat(shmid, 0, 0);

		if ((void*)-1 == shm) {
			std::cout << "child process get memory error!" << std::endl;
			exit(-1);
		}

		char* ptr = (char*)shm;

		int i = 0;
		while (i < 10) {
			*ptr = 'c';
			ptr++;
			i++;
		}

		if (-1 == shmdt(shm)) {
			std::cout << "child process shmdt failed!" << std::endl;
			exit(-2);
		}

		std::cout << "child precess end!" << std::endl;
	}
	else {
		int status;
		wait(&status);
		std::cout << "this is parent precess!" << std::endl;

		int shmid = shmget(key, 10, 0666 | IPC_CREAT);
		shm = shmat(shmid, 0, 0);

		if ((void*)-1 == shm) {
			std::cout << "parent process get memory error!" << std::endl;
			exit(-1);
		}

		char* ptr = (char*)shm;

		int i = 0;
		while (i < 10) {
			printf("%c", *ptr++);
			i++;
		}

		if (shmdt(shm) == -1) {
			std::cout << "parent process end!" << std::endl;
			exit(-2);
		}

		if (shmctl(shmid, IPC_RMID, 0) == -1) {
			std::cout << "parent process delete memory failed!" << std::endl;
			exit(-2);
		}

		std::cout << "\nparent process end!" << std::endl;
	}

	return 0;
}