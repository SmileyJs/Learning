#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE 1024

int
main(int argc, char const *argv[])
{
	int n, int1, int2;
	char buf[MAX_LINE];

	// io
	// while (0 != (n = read(STDIN_FILENO, buf, MAX_LINE))) {
	// 	if (2 == sscanf(buf, "%d %d", &int1, &int2)) {
	// 		sprintf(buf, "%d\n", int1 + int2);
	// 		int n = strlen(buf);
	// 		if (n != write(STDOUT_FILENO, buf, n)) {
	// 			printf("write result failed!\n");
	// 			return -1;
	// 		}
	// 	}
	// 	else {
	// 		if (17 != write(STDOUT_FILENO, "invalid argument\n", 17)) {
	// 			printf("write failed!\n");
	// 			return -1;
	// 		}
	// 	}
	// }

	// set stdio as line buffer
	if (0 != setvbuf(stdin, NULL, _IOLBF, 0))
		printf("setvbuf stdin failed!\n");
	if (0 != setvbuf(stdout, NULL, _IOLBF, 0))
		printf("setvbuf stdout failed!\n");

	// standard io
	while (NULL != fgets(buf, MAX_LINE, stdin)) {
		if (2 == sscanf(buf, "%d %d", &int1, &int2)) {
			sprintf(buf, "%d\n", int1 + int2);
			int n = strlen(buf);
			// if (EOF == fputs(buf, stdout)) {
			// 	printf("fputc error!\n");
			// 	return -1;
			// }
			if (EOF == printf("%d\n", int1 + int2)) {
				printf("printf error!\n");
				return -1;
			}
		}
		else {
			// if (EOF == fputs("invalid argument\n", stdout)) {
			// 	printf("fputs error!\n");
			// 	return -1;
			// }
			if (EOF == printf("invalid argument!\n")) {
				printf("printf invalid error!\n");
				return -1;
			}
		}
	}

	return 0;
}