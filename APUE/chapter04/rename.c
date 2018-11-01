#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int
main(int argc, char const *argv[])
{
	if (0 != rename("bar", "newBar")) {
		printf("rename failed!\n");
		return -1;
	}

	return 0;
}