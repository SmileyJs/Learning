#include <iostream>

#include "Vec.h" 

using namespace std;

int
main(int argc, char const *argv[])
{
	Vec<int> v1{1, 2, 3, 4, 5, 6, 7};

	for (auto i = 0; i != v1.size(); ++i) {
		cout << v1[i] << endl;
	}

	Vec<int> v2 = v1;

	for (auto i : v2) {
		cout << i << endl;
	}

	v2.reserve(10);

	v2.resize(15, 1);

	for (auto i : v2) {
		cout << i << endl;
	}

	Vec<string> v3{"aa", "bb", "cc", "dd", "ee"};

	for (auto i : v3) {
		cout << i << endl;
	}

	cout << v1[1] << v2[0] << v3[4] << endl;

	return 0;
}