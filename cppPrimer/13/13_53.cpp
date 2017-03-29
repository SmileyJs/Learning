#include "HasPtr.h"

int
main(int argc, char const *argv[])
{
	HasPtr a("a");
	HasPtr b("b");

	cout << "before swap " << a.show() << " " << b.show() << endl;

	swap(a, b);

	cout << "after swap " << a.show() << " " << b.show() << endl;

	return 0;
}