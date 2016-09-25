#include "chapter6.h"

int
main(int argc, char const *argv[])
{
	cout << "Please input two number!" << endl;

	int i = 0;
	int j = 0;

	cin >> i >> j;
	cout << "The two input number is " << i << " and " << j << endl;

	swap(&i, &j);

	cout << "After swap is " << i << " and " << j << endl;

	return 0;
}

void
swap(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
	cout << "swap" << endl;
}