#include "HasPtr.h"
#include <chrono>

using namespace std::chrono;
int
main(int argc, char const *argv[])
{
	HasPtr a("a", 1);
	HasPtr b("b", 2);

	cout << "before swap " << a.show() << " " << b.show() << endl;
	auto t0 = high_resolution_clock::now();
	for (int i = 0; i < 1000000; ++i) {
		swap(a, b);
	}
	auto t1 = high_resolution_clock::now();
	cout << duration_cast<milliseconds>(t1-t0).count() << "ms" << endl;

	cout << "after swap " << a.show() << " " << b.show() << endl;

	return 0;
}