#include "StrVec.h"

int
main(int argc, char const *argv[])
{
	StrVec a{"aa", "bb", "cc", "dd", "ee"};
	for (auto i : a) {
		cout << i << endl;
	}

	StrVec b(a);
	for (auto i : b) {
		cout << i << endl;
	}

	StrVec c;
	for (auto i : c) {
		cout << i << endl;
	}

	c = b;

	for (auto i = c.begin(); i != c.end(); ++i) {
		cout << *i << endl;
	}

	c.push_back("ff");

	for (auto i = 0; i != c.size(); ++i) {
		cout << c.at(i) << endl;
	}

	cout << "c.capacity = " << c.capacity() << endl;
	cout << "a.capacity = " << a.capacity() << endl;

	c.reserve(20);

	cout << "c.capacity = " << c.capacity() << endl;

	c.resize(3);
	for (auto i = 0; i != c.size(); ++i) {
		cout << c.at(i) << endl;
	}

	c.resize(20, "jsssssss");
	for (auto i = 0; i != c.size(); ++i) {
		cout << c.at(i) << endl;
	}

	return 0;
}