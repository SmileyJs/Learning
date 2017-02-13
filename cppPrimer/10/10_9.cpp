#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<string> vec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	
	for (auto i : vec) {
		cout << i << endl;
	}

	cout << "========" << endl;

	sort(vec.begin(), vec.end());

	for (auto i : vec) {
		cout << i << endl;
	}

	cout << "========" << endl;

	auto end_unique = unique(vec.begin(), vec.end());

	for (auto i : vec) {
		cout << i << endl;
	}

	cout << "========" << endl;

	vec.erase(end_unique, vec.end());

	for (auto i : vec) {
		cout << i << endl;
	}

	return 0;
}