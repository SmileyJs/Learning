#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int
main(int argc, char const *argv[])
{
	int fd = open("test.txt", O_RDWR);

	if (-1 == fd) {
		printf("open failed!\n");
		return -1;
	}

	struct flock fl;
	fl.l_type = F_WRLCK;
	fl.l_start = 0;
	fl.l_len = 0;
	fl.l_whence = SEEK_SET;

	if (-1 == fcntl(fd, F_SETLK, &fl)) {
		printf("lock failed!\n");
		return -1;
	}

	pid_t pid;
	if (0 > (pid = fork())) {
		printf("fork failed\n");
	}
	else if (0 == pid) {
		int val = 0;
		printf("child\n");
		if (-1 == (val = fcntl(fd, F_GETLK, &fl))) {
			printf("get lock failed! err %s pid is %d\n", strerror(errno), fl.l_pid);
		}
		else {
			if (fl.l_type == F_UNLCK) {
				printf("child unlock\n");
			}
			else {
				printf("child locked pid %d\n", fl.l_pid);
			}
		}

		if (-1 == fcntl(fd, F_SETLK, &fl)) {
			printf("child lock failed! err %s\n", strerror(errno));
		}
	}
	else {
		printf("parent %d child %d\n", getpid(), pid);
	}

	while(1) {
		sleep(1);
	}

	return 0;
}