#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int
lock_reg(int fd, int cmd, int type, int whence, off_t start, off_t len)
{
	struct flock lock;
	lock.l_type = type;
	lock.l_whence = whence;
	lock.l_start = start;
	lock.l_len = len;

	return fcntl(fd, cmd, &lock);
}

int
main(int argc, char const *argv[])
{
	pid_t pid1, pid2, pid3;
	int fd;

	if (-1 == (fd = open("test.txt", O_RDWR))) {
		printf("open failed!\n");
		return -1;
	}

	if (0 > (pid1 = fork())) {
		printf("fork1 failed!\n");
		return -1;
	}
	else if (0 == pid1) {
		if (-1 == lock_reg(fd, F_SETLKW, F_RDLCK, SEEK_SET, 0, 1)) {
			printf("child1 locked failed!\n");
		}
		printf("child1 locked\n");
		pause();
		printf("child1 exit\n");
		exit(0);
	}
	else {
		sleep(1);
	}

	if (0 > (pid2 = fork())) {
		printf("fork2 failed!\n");
	}
	else if (0 == pid2) {
		if (-1 == lock_reg(fd, F_SETLKW, F_RDLCK, SEEK_SET, 0, 1)) {
			printf("child1 locked failed!\n");
		}
		printf("child2 locked\n");
		pause();
		printf("child2 exit\n");
		exit(0);
	}
	else {
		sleep(1);
	}

	if (0 > (pid3 = fork())) {
		printf("fork3 failed!\n");
	}
	else if (0 == pid3) {
		if (-1 == lock_reg(fd, F_SETLKW, F_WRLCK, SEEK_SET, 0, 1)) {
			printf("child3 locked failed!\n");
		}
		printf("child3 locked!\n");
		pause();
		printf("child3 exit\n");
		exit(0);
	}
	else {
		sleep(1);
	}

	if (-1 == lock_reg(fd, F_SETLKW, F_RDLCK, SEEK_SET, 0, 1)) {
		printf("parent locked failed!\n");
	}
	else {
		printf("parent lock success\n");
	}

	pause();
	return 0;
}