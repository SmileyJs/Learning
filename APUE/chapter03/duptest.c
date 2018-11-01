#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>


const char *buf = "hahahahaha===============jsssssssssssssssssss";

int
main(int argc, char const *argv[])
{
	int fd;

	if (0 > (fd =  open("testFile.txt", O_RDWR | O_CREAT | O_EXCL | O_APPEND))) {
		printf("file open failed!\n");
		return -1;
	}

	printf("%ld\n", sizeof(buf));

	int n = write(fd, buf, 10);

	if (n != 10) {
		printf("write failed!\n");
		return -1;	
	}

	pid_t pid = fork();

	if (-1 == pid) {
		printf("fork failed!\n");
		return -1;
	}
	else if (0 == pid) {
		printf("child process\n");

		int fd2 = dup(fd);

		int ret = write(fd2, buf, 10);
		if (ret != 10) {
			printf("child precess write failed!\n");
			exit(-1);
		}
	}
	else {
		usleep(100);
		printf("father precess\n");

		write(fd, buf, 20);
	}



	return 0;
}