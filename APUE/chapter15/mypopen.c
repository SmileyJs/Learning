#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

static pid_t *childPid = NULL;

#define MAX_FILENO	1024

FILE*
my_popen(const char *cmd, const char *type)
{
	if ((type[0] != 'r' && type[0] != 'w') || type[1] != 0) {
		printf("popen argument error!\n");
		return NULL;
	}

	if (NULL == childPid) {
		childPid = malloc(sizeof(pid_t) * MAX_FILENO);
		if (NULL == childPid) {
			printf("malloc failed!\n");
			return NULL;
		}
	}

	int pfd[2];
	pid_t pid;


	if (0 > pipe(pfd)) {
		printf("pipe failed!\n");
		return NULL;
	}

	if (pfd[0] > MAX_FILENO || pfd[1] > MAX_FILENO) {
		close(pfd[0]);
		close(pfd[1]);
		return NULL;
	}

	if (0 > (pid = fork())) {
		printf("fork failed!\n");
		return NULL;
	}
	else if (0 == pid) {
		if ('r' == type[0]) {
			close(pfd[0]);
			if (pfd[1] != STDOUT_FILENO) {
				dup2(pfd[1], STDOUT_FILENO);
				close(pfd[1]);			
			}
		}
		else {
			close(pfd[1]);
			if (pfd[0] != STDIN_FILENO) {
				dup2(pfd[0], STDIN_FILENO);
				close(pfd[0]);
			}
		}

		for (int i = 0; i != MAX_FILENO;++i) {
			if (childPid[i] > 0)
				close(childPid[i]);
		}

		if (-1 == execl("/bin/bash", "sh", "-c", cmd, (char*)0)) {
			printf("execl failed!\n");
		}

		_exit(127);
	}

	FILE *fp;

	if (type[0] == 'r') {
		close(pfd[1]);
		if (NULL == (fp = fdopen(pfd[0], "r"))) {
			printf("fdopen failed!\n");
			return NULL;
		}
	}
	else {
		close(pfd[0]);
		if (NULL == (fp = fdopen(pfd[1], "w"))) {
			printf("fdopen write failed!\n");
			return NULL;
		}
	}

	childPid[fileno(fp)] = pid;
	return fp;
}

int
my_pclose(FILE *fp)
{
	if (NULL == fp) {
		printf("fp is null\n");
		return -1;
	}

	if (NULL == childPid) {
		printf("childPid is NULL\n");
		return -1;
	}

	int fd = fileno(fp);
	if (fd > MAX_FILENO) {
		printf("invalid fd\n");
		return -1;
	}

	pid_t pid;
	if (0 == (pid = childPid[fd])) {
		printf("pid error!\n");
		return -1;
	}

	childPid[fd] = 0;
	if (EOF == fclose(fp)) {
		printf("fclose failed!\n");
		return -1;
	}

	int status;
	if (-1 == waitpid(pid, &status, 0)) {
		if (errno != EINTR)
			return -1;
	}

	return status;
}

int
main(int argc, char const *argv[])
{
	FILE* fp = my_popen("myuclc", "r");

	if (NULL == fp) {
		printf("my_popen failed!\n");
		return -1;
	}

	char line[1024];

	while (1) {
		fputs("prompt>", stdout);
		fflush(stdout);
		if (NULL == fgets(line, 1024, fp))
			break;
		if (EOF == fputs(line, stdout))
			printf("fputs failed!\n");
	}

	my_pclose(fp);

	return 0;
}