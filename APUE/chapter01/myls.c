#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#include <errno.h>
#include <string.h>

int
main(int argc, char const *argv[])
{
	if (2 != argc) {
		printf("arguments error\n");
		exit(-1);
	}

	DIR *fd;
	struct dirent *entry;

	if (NULL == (fd = opendir(argv[1]))) {
		printf("opendir failed!\n");
		exit(-2);
	}
	
	while ((entry = readdir(fd))) {
		printf("%s\n", entry->d_name);
	}

	closedir(fd);

	printf("test errno %s\n", strerror(errno));

	return 0;
}