#include <stdio.h>

int
main(int argc, char const *argv[])
{
	FILE *fp;

	if (NULL == (fp = popen("ks", "r"))) {
		printf("popen failed!\n");
	}

	char buf[1024];

	while (0 != fread(buf, 1, sizeof(buf), fp)) {
		printf("%s\n", buf);
	}

	if (ferror(fp)) {
		printf("fread failed!\n");
		return -1;
	}

	return 0;
}