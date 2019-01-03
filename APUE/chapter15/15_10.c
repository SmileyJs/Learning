#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO "test.fifo"

int
main(int argc, char const *argv[])
{
	unlink(FIFO);

	if (-1 == mkfifo(FIFO, 0666)) {
		printf("mkfifo failed!\n");
		return -1;
	}

	int fdRead, fdWrite;

	if (-1 == (fdRead = open(FIFO, O_RDONLY | O_NONBLOCK))) {
		printf("open read failed!\n");
		return -1;
	}

	if (-1 == (fdWrite = open(FIFO, O_WRONLY))) {
		printf("opoen write failed!\n");
		return -1;
	}

	return 0;
}