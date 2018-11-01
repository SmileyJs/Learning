#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

static long nreg, ndir, nchr, nfifo, nblk, nslink, nsock, ntot; 

#define FT_F	1
#define FT_D	2
#define FT_DNR	3
#define FT_NS	4

static char fullPath[PATH_MAX];
static size_t pathLen;

static int count = 0;

typedef int MyFunc(const char*, const struct stat *, int);

static MyFunc myfunc;

static int myfunc(const char *pathname, const struct stat *statptr, int type)
{
	switch (type) {
	case FT_F:
		switch (statptr->st_mode & S_IFMT) {
			case S_IFREG:
				nreg++;
				break;
			case S_IFBLK:
				nblk++;
				break;
			case S_IFCHR:
				nchr++;
				break;
			case S_IFIFO:
				nfifo++;
				break;
			case S_IFLNK:
				nslink++;
				break;
			case S_IFSOCK:
				nsock++;
				break;
			default:
				printf("is S_IFDIR for %s\n", pathname);
				return -2;
		}
		break;
	case FT_D:
		ndir++;
		break;
	case FT_NS:
		printf("stat error for %s\n", pathname);
		return -1;
		break;
	case FT_DNR:
		printf("can't read directory %s\n", pathname);
		return -1;
		break;
	default:
		printf("unknow type %d for %s\n", type, pathname);
		return -2;
	}

	return 0;	
}


static int doPath(MyFunc func)
{
	struct stat sb;
	struct dirent *dirp;
	DIR *dp;

	int ret = 0;
	int n = 0;
	
	if (-1 == lstat(fullPath, &sb)) {
		return func(fullPath, &sb, FT_NS);
	}

	if (!S_ISDIR(sb.st_mode)) {
		return func(fullPath, &sb, FT_F);
	}

	if (0 != (ret = func(fullPath, &sb, FT_D))) {
		return ret;
	}

	n = strlen(fullPath);

	fullPath[n++] = '/';
	fullPath[n] = 0;

	if (NULL == (dp = opendir(fullPath))) {
		return func(fullPath, &sb, FT_DNR);
	}

	while (NULL != (dirp = readdir(dp))) {
		// printf("%d\n", count++);
		if (strcmp(".", dirp->d_name) == 0
			|| strcmp("..", dirp->d_name) == 0)
			continue;
		printf("%s\n", dirp->d_name);
		strcpy(&fullPath[n], dirp->d_name);
		doPath(func);
	}

	fullPath[n-1] = 0;

	if (-1 == closedir(dp)) {
		printf("closedir failed!\n");
		return -1;
	}

	return 0;
}

int myftw(const char *path, MyFunc func)
{
	strcpy(fullPath, path);
	return doPath(func);
}

int
main(int argc, char const *argv[])
{
	if (argc != 2) {
		printf("argument error!\n");
		return -1;
	}

	if (0 > myftw(argv[1], myfunc)) {
		printf("myftw failed!\n");
		return -2;
	}

	ntot = nreg + ndir + nchr + nblk + nslink + nsock + nfifo;

	printf("regular %ld %ld%%\n", nreg, nreg*100 / ntot);
	printf("dir %ld %ld%%\n", ndir, ndir*100 / ntot);
	printf("char special %ld %ld%%\n", nchr, nchr*100 / ntot);
	printf("blk special %ld %ld%%\n", nblk, nblk*100 / ntot);
	printf("slink %ld %ld%%\n", nslink, nslink*100 / ntot);
	printf("nfifo %ld %ld%%\n", nfifo, nfifo*100 / ntot);
	printf("nsock %ld %ld%%\n", nsock, nsock*100 / ntot);

	return 0;
}
