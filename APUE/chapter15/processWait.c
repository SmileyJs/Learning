#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	if (1 != write(pfd2[1], "c", 1)) {
		printf("%s write failed!\n", __FUNCTION__);
	}
}

void WAIT_CHILD()
{
	char c;

	if (-1 == read(pfd2[0], &c, 1)) {
		printf("%s read failed!\n",__FUNCTION__ );
	}

	if (c != 'c') {
		printf("%s invalid data\n", __FUNCTION__);
	}
}

void TELL_CHILD()
{
	if (1 != write(pfd1[1], "p", 1)) {
		printf("%s write failed!\n", __FUNCTION__);
	}
}

int
main(int argc, char const *argv[])
{
	pid_t pid;

	TELL_WAIT();

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
	}
	else if (0 == pid) {
		sleep(1);
		printf("child start\n");
		TELL_PARENT();
		printf("receiev parent\n");
		WAIT_PARENT();
		printf("child end\n");
	}
	else {
		printf("parnet start\n");
		WAIT_CHILD();
		printf("receiev child\n");
		TELL_CHILD();
		printf("parent end\n");
	}

	return 0;
}