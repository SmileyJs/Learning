#include <iostream>

using std::endl;
using std::cout;
using std::cin;

void foo(int b);
void bar(int m);

int
main(void)
{
	int a;
	char *s = "hello, world!";
	printf("%s\n", &s[7]);

	a = 5;
	foo(a);

	return 0;
}

void
foo(int b)
{
	int n = b;
	n *= 2;
	bar(n);
}

void
bar(int m)
{
	printf("hello, i'm bar!\n");
}
