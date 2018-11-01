#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int
main(int argc, char const *argv[])
{
	const int size = 4096;
	const char *name = "OS";
	
	int shm_fd;
	void *ptr;

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	ptr = mmap(0, size, PROT_READ, MAP_SHARED, shm_fd, 0);

	printf("%s\n", (char*)ptr);

	shm_unlink(name);

	return 0;
}