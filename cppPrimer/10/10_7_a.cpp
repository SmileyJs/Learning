#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<int> vec;
	list<int> lst;
	int i;

	while (cin >> i) {
		lst.push_back(i);
	}

	copy(lst.cbegin(), lst.cend(), back_inserter(vec));

	for (auto i : vec) {
		cout << i << endl;
	}

	return 0;
}