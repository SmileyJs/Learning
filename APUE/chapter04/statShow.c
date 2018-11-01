#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void printStat(const char* path)
{

}

int
main(int argc, char const *argv[])
{
	// if (argc != 2) {
	// 	printf("argument error\n");
	// 	return -1;
	// }

	struct stat buf;

	for (int i = 1; i != argc; ++i) {
		printf("%s: ", argv[i]);

		if (0 > stat(argv[i], &buf)) {
			printf("stat execute failed!\n");
			return -1;
		}

		if (S_ISREG(buf.st_mode)) {
			printf("regular file\n");
		}
		else if (S_ISDIR(buf.st_mode)) {
			printf("directory\n");
		}
		else if (S_ISCHR(buf.st_mode)) {
			printf("character special\n");
		}
		else if (S_ISBLK(buf.st_mode)) {
			printf("block special\n");
		}
		else if (S_ISFIFO(buf.st_mode)) {
			printf("FIFO\n");
		}
		else if (S_ISSOCK(buf.st_mode)) {
			printf("socket\n");
		}
		else if (S_ISLNK(buf.st_mode)) {
			printf("symbolic link\n");
		}
		else {
			printf("else\n");
		}

		if (S_ISUID == (buf.st_mode & S_IFMT)) {
			printf("user id\n");
		}
		else {
			printf("is not user id\n");
		}
		// else if (S_ISGID(buf.st_mode)) {
			// printf("group id\	n");
		// }
	}

	return 0;
}