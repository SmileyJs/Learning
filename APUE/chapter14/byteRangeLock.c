#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int
lock_reg(int fd, int cmd, int type, off_t start, int whence, off_t len)
{
	struct flock lock;

	lock.l_type = type;
	lock.l_start = start;
	lock.l_whence = whence;
	lock.l_len = len;

	return fcntl(fd, cmd, &lock);
}

int
lock_test(int fd, int type, off_t start, int whence, off_t len)
{
	struct flock lock;

	lock.l_type = type;
	lock.l_start = start;
	lock.l_whence = whence;
	lock.l_len = len;

	if (-1 == fcntl(fd, F_GETLK, &lock)) {
		printf("fnctl error!\n");
		return -1;
	}

	if (F_UNLCK == lock.l_type)
		return 0;

	return lock.l_pid;
}

int
lockAByte(const char* name, off_t start, int fd)
{
	printf("%s %s\n", __FUNCTION__, name);

	if (0 != lock_reg(fd, F_SETLKW, F_WRLCK, start, SEEK_SET, 1)) {
		printf("lock failed! err %s\n", strerror(errno));
		return -1;
	}

	return 0;
}

int
main(int argc, char const *argv[])
{
	int fd;
	pid_t pid;

	if (-1 == (fd = open("test.txt", O_RDWR))) {
		printf("open failed!\n");
		return -1;
	}

	printf("%d\n", lock_test(fd, F_RDLCK, 0, SEEK_SET, 100));

	if (0 > (pid = fork())) {
		printf("fork failed!");
	}
	else if (0 == pid) {
		printf("child\n");
		lockAByte("child", 0, fd);
		sleep(1);
		// lockAByte("child", 1, fd);
	}
	else {
		printf("father\n");
		// lockAByte("parent", 1, fd);
		sleep(1);
		lockAByte("parent", 0, fd);
	}

	return 0;
}