#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print(const vector<string> &vec) {
	for (auto i : vec) {
		cout << i << endl;
	}

	cout << "===" << endl;
}

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

int
main(int argc, char const *argv[])
{
	vector<string> vec{"the", "quick", "red", "fox", "jumps",
		"over", "the", "slow", "red", "turtle"};

	sort(vec.begin(), vec.end());

	print(vec);

	auto end_unique = unique(vec.begin(), vec.end());

	print(vec);

	vec.erase(end_unique, vec.end());

	print(vec);

	stable_sort(vec.begin(), vec.end(), isShorter);

	print(vec);

	return 0;
}