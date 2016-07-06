#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int
main()
{
/**
	int a[] = {0, 1, 2, 3, 4, 5};

	vector<int> vec(begin(a), begin(a) + 3);

	for (int i : vec) {
		cout << i << endl;
	}
 */

	vector<int> ivec;

	for (int i = 0; i < 10; ++i) {
		ivec.push_back(i);
	}

	int a[ivec.size()];

	for (int i = 0; i < ivec.size(); ++i) {
		a[i] = ivec[i];
	}

	for (int i : a) {
		cout << i << endl;
	}

	return 0;
}
