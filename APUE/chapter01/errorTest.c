#include <errno.h>
#include <stdio.h>
#include <string.h>

int
main(int argc, char const *argv[])
{
	errno = EACCES;
	printf("%s\n", strerror(errno));

	errno = ENOENT;
	perror("haha");

	return 0;
}