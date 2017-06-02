#include <iostream>

using namespace std;

int
main(int argc, char const *argv[])
{
	int a[3];
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;

	int *p, *q;

	p = a;
	q = &a[2];

	cout << "p:" << p << " =" << *p << endl;
	cout << "q:" << q << " =" << *q << endl;

	cout << p - q << " :" << a[abs(p-q)] << endl;

	return 0;
}