#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool
checkSize(const string &s, string::size_type n)
{
	if (s.size() > n) {
		return true;
	}
	else {
		return false;
	}
}

int
main(int argc, char const *argv[])
{
	if (argc != 2) {
		cout << "argument error!" << endl;
		return -1;
	}

	vector<string> vec{"the", "quick", "red", "fox", "jumps",
		"over", "the", "slow", "red", "turtle"};

	// auto check = bind(checkSize, _1, atoi(argv[1]));

	// auto count = count_if(vec.begin(), vec.end(), check);

	auto count = count_if(vec.begin(), vec.end(), bind(checkSize, _1, atoi(argv[1])));

	cout << "there are " << count << " words of length " << argv[1] << " or longer." << endl;

	return 0;
}