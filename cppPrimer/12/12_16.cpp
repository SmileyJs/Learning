#include <iostream>
#include <memory>

using namespace std;

int
main(int argc, char const *argv[])
{
	unique_ptr<int> p(new int(23));

	// unique_ptr<int> p2 = p;

	// unique_ptr<int> p3(p);

	unique_ptr<int> p4(p.release());

	// p4.reset(p.release());

	cout << *p4 << endl;

	return 0;
}