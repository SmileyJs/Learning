#include <stdio.h>
#include <string.h>

int
main(int argc, char const *argv[])
{
	char buf[1024] = {0};

	sprintf(buf, "haha ");

	printf("%lu\n", strlen(buf));

	return 0;
}