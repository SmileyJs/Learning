#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

int
main(int argc, char const *argv[])
{
	list<string> lst{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

	for (auto i : lst) {
		cout << i << endl;
	}

	lst.sort();

	for (auto i : lst) {
		cout << i << endl;
	}

	lst.unique();

	for (auto i : lst) {
		cout << i << endl;
	}

	return 0;
}