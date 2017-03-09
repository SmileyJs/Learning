#include <iostream>
#include <memory>

using namespace std;

int
main(int argc, char const *argv[])
{
	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;

	// IntP p0(ix);		// not match function to convert int to unique_ptr<int>
	// IntP p1(pi);		// p1 will be freed after quit the scope
	// IntP p2(pi2);	// p2 will be freed after quit the scope
	// IntP p3(&ix);	// p1 will be freed after quit the scope
	IntP p4(new int(2048));	// recommended
	// IntP p5(p2.get());	// p2 will be freed after quit the scope, double free.

	delete pi2;

	return 0;
}