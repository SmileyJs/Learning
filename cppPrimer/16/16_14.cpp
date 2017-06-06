#include "Screen.h"

int
main(int argc, char const *argv[])
{
	Screen<5, 5> a('s');

	a.set(2, 3, 'A');

	cout << a << endl;

	a.move(1, 1);

	cin >> a;

	cout << a << endl;

	return 0;
}