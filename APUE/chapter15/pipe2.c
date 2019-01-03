#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define DEF_PAGER "/bin/more"

#define MAX_LINE 1024

int
main(int argc, char const *argv[])
{
	if (2 != argc) {
		printf("argument error!\n");
		return -1;
	}

	FILE *fp;

	if (NULL == (fp = fopen(argv[1], "r"))) {
		printf("fopen failed!\n");
		return -1;
	}

	int fd[2];
	pid_t pid;
	char line[MAX_LINE] = {0};

	if (0 > pipe(fd)) {
		printf("pipe failed!\n");
		return -1;
	}

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
		return -1;
	}
	else if (0 == pid) {
		close(fd[1]);

		if (fd[0] != STDIN_FILENO) {
			if (STDIN_FILENO != dup2(fd[0], STDIN_FILENO)) {
				printf("dup2 failed!\n");
				return -1;
			}
			close(fd[0]);
		}

		// normal environment usage.
		char *pager, *argv0;
		if (NULL == (pager = getenv("PAGER"))) {
			pager = DEF_PAGER;
		}
		if (NULL == (argv0 = strrchr(pager, '/'))) {
			argv0 = pager;
		}
		else {
			argv0++;
		}
		printf("pager = %s,  argv0 = %s\n", pager, argv0);

		if (0 > execl(pager, argv0, (char*)0)) {
			printf("execl failed!\n");
			return -1;
		}
	}
	else {
		close(fd[0]);

		while (NULL != fgets(line, MAX_LINE, fp)) {
			int len = strlen(line);

			if (0 > write(fd[1], line, len)) {
				printf("write failed!\n");
				return -1;
			}
		}

		if (ferror(fp)) {
			printf("fgets error!\n");
		}

		close(fd[1]);

		if (0 > waitpid(pid, NULL, 0)) {
			printf("waitpid failed!\n");
		}
	}

	return 0;
}