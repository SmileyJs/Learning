#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

static jmp_buf jmpbuffer;

static int e;

void cmd_add(int i)
{
	printf("%s\n", __FUNCTION__);

	if (4 == i)
		longjmp(jmpbuffer, 1);
}

void f1(int i, int j, int k, int l)
{
	printf("%s a = %d, b = %d, c = %d, f = %d, e = %d\n", __FUNCTION__, i, j, k, l, e);
}

void f2()
{
	longjmp(jmpbuffer, 2);
}

int
main(int argc, char const *argv[])
{
	int a;
	register int b;
	volatile int c;
	static int d;

	a = 1, b = 2, c = 3, d = 4, e = 5;

	if (0 != setjmp(jmpbuffer)) {
		printf("error\n");
		printf("a = %d, b = %d, c = %d, d = %d, e = %d\n", a, b, c, d, e);
		return -1;
	}

	a = 91, b = 92, c = 93, d = 94, e = 95;

	f1(a, b, c, d);

	f2();

	// for (int i = 0; i != 5; ++i)
	// 	cmd_add(i);

	return 0;
}