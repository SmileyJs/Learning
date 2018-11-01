#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_exit1(void)
{
	printf("my_exit1\n");
}

void my_exit2(void)
{
	printf("my_exit2\n");
}

int
main(int argc, char const *argv[], const char *envp[])
{
	printf("%d\n", _SC_ATEXIT_MAX);

	if (0 != atexit(my_exit1))
		printf("register my_exit1 failed!\n");

	if (0 != atexit(my_exit2))
		printf("register my_exit2 failed!\n");

	if (0 != atexit(my_exit1))
		printf("register my_exit1 failed\n");

	for (int i = 0; argv[i] != NULL; i++) {
		printf("%s\n", argv[i]);
	}

	for (int i = 0; envp[i] != NULL; i++) {
		printf("%s\n", envp[i]);
	}

	return 0;
}