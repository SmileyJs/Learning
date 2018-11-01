#include <iostream>

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getFibanacci(int i)
{
	if (0 == i)
		return 0;
	else if (1 == i)
		return 1;
	else
		return getFibanacci(i - 1) + getFibanacci(i - 2);
}

void generateFibonacci(int num, char* buf)
{
	printf("generateFibonacci\n");

	if (num < 1) {
		printf("the num is too small\n");
		return;
	}

	for (int i = 0; i < num; ++i) {
		int ret = getFibanacci(i);
		printf("%d ", ret);
		sprintf(buf, "%d ", ret);
		buf++;
		buf++;	
	}	

	printf("\ngenerateFibonacci end\n");
}

int
main(int argc, char const *argv[])
{
	if (argc < 2) {
		printf("argument error!\n");
		return -1;
	}

	int num = atoi(argv[1]);

	pid_t p1 = fork();

	if (0 > p1) {
		printf("fork error!\n");
		return -1;
	}

	if (0 == p1) {
		std::cout << "This is child process P1 " << getpid() << std::endl;
		execlp("ls", "ls");
		exit(0);
	}
	else {
		wait(&p1);
		std::cout << "This is father process " << getpid() << std::endl;
	}

	int fileDescribe[2];

	if (-1 == pipe(fileDescribe)) {
		printf("pipe error!\n");
		exit(-1);
	}

	pid_t p2 = fork();

	if (0 > p2) {
		printf("fork error\n");
		return -1;
	}

	int rtnCount = 0;
	char buf[100];
	memset(buf, 0, 100);

	if (0 == p2) {
		std::cout << "This is child process p2 " << getpid() << std::endl;
	
		close(fileDescribe[0]);
		generateFibonacci(num, buf);

		rtnCount = write(fileDescribe[1], buf, strlen(buf));
		printf("write size is %d\n", rtnCount);

		exit(0);
	}
	else {
		wait(&p2);
		std::cout << "This is father process " << getpid() << std::endl;
	
		close(fileDescribe[1]);
		rtnCount = read(fileDescribe[0], buf, sizeof(buf));
		printf("read size is %d, content:%s\n", rtnCount, buf);
	}

	return 0;
}