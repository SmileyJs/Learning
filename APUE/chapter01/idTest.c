#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>

int
main(int argc, char const *argv[])
{
	printf("pid = %d, uid = %d, gid = %d\n", getpid(), getuid(), getgid());
	return 0;
}