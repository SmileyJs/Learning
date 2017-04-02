#include "Foo.h"

int
main(int argc, char const *argv[])
{
	Foo a = {12, 2, 4, 5};
	a.sorted();

	cout << "separet=========" << endl;

	Foo(a).sorted();
	return 0;
}