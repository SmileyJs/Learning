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

	vec[1].swap(vec[6]);

	cout << *vec[1] << endl;
	cout << *vec[6].get() << endl;

	cout << "unique ptr" << endl;

	vector<string> v1{"aa", "bb", "cc", "dd", "ee"};

	UniquePtr<string> pu1(new string("aa"));
	UniquePtr<string> pu2(new string("bb"));
	UniquePtr<string> pu3(new string("vv"));

	cout << *pu1.get() << endl;
	cout << *pu1 << endl;

	pu1.swap(pu3);

	cout << *pu1 << endl;

	return 0;
}