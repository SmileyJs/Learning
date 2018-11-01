#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>

void collatz(int* n)
{
	if (*n % 2) {
		*n = *n*3 + 1;
	}
	else {
		*n /= 2;
	}
}

int
main(int argc, char const *argv[])
{
	if (2 != argc) {
		printf("argument error!\n");
		return -1;
	}

	int num = atoi(argv[1]);

	if (0 > num) {
		printf("argument should > 0\n");
		return -1;
	}

	int shm_fd;
	const char* name = "shmName";
	int size = 256;

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0x0666);
	if (0 > shm_fd) {
		printf("shm_opem failed!\n");
		return -1;
	}

	if (-1 == ftruncate(shm_fd, size)) {
		printf("ftruncate failed!\n");
		return -1;
	}

	void* ptr = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);

	pthread_t pid;

	pid = fork();

	if (-1 == pid) {
		printf("fork failed!\n");
		return -1;
	}
	else if (0 == pid) {
		printf("child process\n");

		char* str;
		sprintf(str, "%d", num);
		sprintf((char*)ptr, "%s", str);
		ptr += strlen(str);

		while (num > 1) {
			collatz(&num);
			sprintf(str, ", %d", num);
			sprintf((char*)ptr, "%s", str);
			ptr += strlen(str);
		}
	}
	else {
		wait(NULL);
		printf("parent process num = %d\n", num);
		printf("%s\n", (char*)ptr);

		shm_unlink(name);
	}

	return 0; 	
}