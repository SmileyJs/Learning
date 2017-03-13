#include <iostream>
#include <memory>

using namespace std;

int
main(int argc, char const *argv[])
{
	allocator<string> a;
	auto p = a.allocate(10);

	auto q = p;
	string text;

	while (cin >> text && q != p + 10) {
		a.construct(q++, text);
	}

	while (q != p) {
		cout << *(--q) << endl;
		a.destroy(q);
	}

	a.deallocate(p, 10);

	return 0;
}