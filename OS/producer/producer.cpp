#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int
main(int argc, char const *argv[])
{
	const int size = 4096;
	const char *name = "OS";
	const char *message0 = "hello";
	const char *message1 = "world!";

	int shm_fd;
	void *ptr;

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	ftruncate(shm_fd, size);
	ptr = mmap(0, size, PROT_WRITE, MAP_SHARED, shm_fd, 0);

	char *p = (char*)ptr;

	sprintf(p, "%s", message0);
	p += strlen(message0);
	sprintf(p, "%s", message1);
	p += strlen(message1);

	return 0;
}