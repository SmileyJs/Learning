#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "HasPtr.h"

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<HasPtr> vec({HasPtr("d"), HasPtr("a"), HasPtr("c"), HasPtr("b"), HasPtr("e")});

	for (auto i : vec) {
		cout << i.show() << endl;
	}

	sort(vec.begin(), vec.end());

	for (auto i : vec) {
		cout << i.show() << endl;
	}

	return 0;
}