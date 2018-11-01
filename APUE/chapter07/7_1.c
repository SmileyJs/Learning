#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef void Exitfunc(void);

void my_exit(void)
{
	printf("%s\n", __FUNCTION__);
}

int
main(int argc, char const *argv[])
{
	printf("hello world!\n");
	
	Exitfunc *func = my_exit;

	if (0 != atexit(func)) {
		printf("atexit failed! %s\n", strerror(errno));
	}

	return 0;
}