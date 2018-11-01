#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int
main(int argc, char const *argv[])
{
	int c[SIZE] = {0};
	int n = 0;

	while (EOF != scanf("%d", &c[n++]));
	for (int i = 0; i != n; ++i)
		printf("%d\n", c[i]);

	qsort(c, n, sizeof(int), compare);

	for (int i = 0; i != n; ++i)
		printf("%d\n", c[i]); 

	return 0;
}