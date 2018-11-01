#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int
main(int argc, char const *argv[])
{
	if (0 > mkdir("testDir", S_IRWXU | S_IRWXG | S_IRWXO)) {
		printf("mkdir execute failed!\n");
		return -1;
	}

	system("ls");

	sleep(2);

	if (0 > rmdir("testDir")) {
		printf("rmdir execute failed!\n");
		return -1;
	}

	return 0;
}