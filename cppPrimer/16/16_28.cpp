#include <vector>

#include "Ptr.h"

void TmpDelete(int* p)
{
	cout << __PRETTY_FUNCTION__ << endl;
	delete p;
}

int
main(int argc, char const *argv[])
{
	vector<SharedPtr<int>> vec;

	for (int i = 0; i != 10; ++i) {
		vec.push_back(SharedPtr<int>(new int(i)));
	}

	for (auto i : vec) {
		cout << *i << endl;
	}

	cout << vec[1].unique() << endl;

	if (vec[1]) {
		cout << vec[1].use_count() << endl;
	}

	SharedPtr<int> p1;

	p1 = vec[1];

	cout << *p1 << endl;

	p1.reset(new int(3), TmpDelete);

	cout << *p1.get() << endl;

	return 0;
}