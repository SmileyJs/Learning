#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>

int
main(int argc, char const *argv[])
{
	int fd, count;
	pid_t pid;
	void *area;

	// if (-1 == (fd = open("/dev/zero", O_RDWR))) {
	// 	printf("open failed!\n");
	// 	return -1;
	// }

	if (MAP_FAILED == (area = mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0))) {
		printf("map failed!\n");
		return -1;
	}

	// close(fd);

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
	}
	else if (pid == 0) {
		printf("child process\n");
		sleep(1);
		(*(int*)area)++;
		printf("%d\n", *(int*)area);
	}
	else {
		printf("parent process\n");
		(*(int*)area)++;
		printf("%d\n", *(int*)area);
	}

	return 0;
}