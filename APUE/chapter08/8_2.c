#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void f2()
{
	char buf[1000];

	for (int i = 0; i != sizeof(buf); ++i)
		buf[i] = 0;
}

void f1()
{
	pid_t pid;

	if (0 > (pid = vfork()))
		printf("fork failed!\n");
}

int
main(int argc, char const *argv[])
{
	f1();
	f2();
	return 0;
}