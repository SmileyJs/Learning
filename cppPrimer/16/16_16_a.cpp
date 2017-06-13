#include <iostream>

#include "Vec_b.h"

int
main(int argc, char const *argv[])
{
	Vec<int> v1{1, 2, 3, 4, 5, 6, 7};

	for (auto i : v1) {
		cout << i << endl;
	}

	v1[2] = 10;

	for (auto i : v1) {
		cout << i << endl;
	}

	Vec<int> v2  = v1;

	for (auto i : v2) {
		cout << i << endl;
	}

	v2.resize(10, 9);

	for (auto i : v2) {
		cout << i << endl;
	}

	return 0;
}