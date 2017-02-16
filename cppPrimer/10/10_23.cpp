#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

using namespace std;
using namespace std::placeholders;

bool
checkSize(const string &s, string::size_type sz)
{
	return s.size() < sz;
}

int
main(int argc, char const *argv[])
{
	if (argc != 2) {
		cout << "argument error!" << endl;
		return -1;
	}

	vector<int> vec;
	for (int i = 0; i != 20; ++i) {
		vec.push_back(i);
	}

	auto iter = find_if(vec.begin(), vec.end(), bind(checkSize, argv[1], _1));

	cout << *iter << endl;

	return 0;
}
