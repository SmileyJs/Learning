#include <iostream>

using namespace std;

int a = 0;
int b = 0;

int increment(int a);

void swap();

int
main(int argc, char* argv[])
{
	printf("a = %d\n", a);
	printf("b = %d\n", b);

	printf("increment!!!\n");;
	
	a = increment(a);
	b = increment(increment(b));

	printf("a = %d\n", a);
	printf("b = %d\n", b);

	printf("swaping.......\n");
	swap();

	printf("a = %d\n", a);
	printf("b = %d\n", b);

	return 0;
}

int 
increment(int a)
{
	return ++a;
}

void swap(void)
{
	int tmp = a;
	a = b;
	b = tmp;
}
