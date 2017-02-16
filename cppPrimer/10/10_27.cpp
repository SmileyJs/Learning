#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <list>

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<string> vec{"the", "quick", "red", "fox", "jumps",
		"over", "the", "slow", "red", "turtle"};

	sort(vec.begin(), vec.end());

	list<string> lst;

	unique_copy(vec.begin(), vec.end(), back_inserter(lst));

	for (auto i : lst) {
		cout << i << endl;
	}

	return 0;
}