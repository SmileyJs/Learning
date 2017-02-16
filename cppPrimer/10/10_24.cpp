#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;
using namespace std::placeholders;

bool checkSize(const string &s, string::size_type sz)
{
	return s.size() > sz;
}

int
main(int argc, char const *argv[])
{
	vector<string> vec{"the", "quick", "red", "fox", "jumps",
		"over", "the", "slow", "red", "turtle"};

	if (argc != 2) {
		cout << "argument error!" << endl;
		return -1;
	}

	sort(vec.begin(), vec.end());

	auto new_end = unique(vec.begin(), vec.end());

	vec.erase(new_end, vec.end());

	auto flag = stable_partition(vec.begin(), vec.end(), bind(checkSize, _1, atoi(argv[1])));

	cout << "there are " << flag - vec.begin() << " words of length " << argv[1] << " or longer." << endl;

	for (auto i = vec.begin(); i != flag; ++i) {
		cout << *i << endl;
	}
 
	return 0;
}