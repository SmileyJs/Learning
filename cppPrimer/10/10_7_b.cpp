#include <algorithm>
#include <iostream>

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<int> vec;

	// vec.reserve(10); vec's size still is 0
	vec.resize(10);

	fill_n(vec.begin(), 10, 0);

	for (auto i : vec) {
		cout << i << endl;
	}

	return 0;
}