#include "chapter6.h"

int 
main(int argc, char const *argv[])
{
	f(2.56, 42); // ambiguous
	f(42);
	f(42, 0);
	f(2.56, 3.14);

	return 0;
}

void f() 
{
	cout << "1" << endl;
	return;
}

void f(int a)
{
	cout << "2" << endl;
	return;
}

void f(int a, int b)
{
	cout << "3" << endl;
	return;
}

void f(double a, double b)
{
	cout << "4" << endl;
	return;
}