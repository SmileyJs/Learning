#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

int create_tmp(char* tmp)
{
	int fd;
	struct stat sb;

	if (-1 == (fd = mkstemp(tmp)))
		printf("mkstemp faied!\n");

	printf("tmp name %s\n", tmp);

	if (-1 == stat(tmp, &sb)) {
		printf("%s\n", strerror(errno));
	}
	else {
		printf("tmp file exist\n");
		unlink(tmp);
	}

	return 0;
}


int
main(int argc, char const *argv[])
{
	char name[L_tmpnam] = {0};
	char line[1024] = {0};

	FILE *fp;

	printf("%s\n", tmpnam(NULL));

	tmpnam(name);

	printf("%s\n", name);

	if (NULL == (fp = tmpfile()))
		printf("tmpfile failed!\n");

	fputs("one line to out put\n", fp);
	rewind(fp);

	if (NULL == fgets(line, sizeof(line), fp))
		printf("fgets failed\n");

	fputs(line, stdout);

	char good_tem[] = "/tmp/dirXXXXXX";
	char *bad_tum = "/tmp/dirXXXXXX";

	printf("good %p \t bad %p\n", good_tem, bad_tum);

	create_tmp(good_tem);
	// create_tmp(bad_tum);

	return 0;
}