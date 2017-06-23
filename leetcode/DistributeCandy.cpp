#include <iostream>
#include <vector>
#include <set>

using namespace std;

int distribute(vector<int>& candies)
{
	set<int> numSet;

	for (auto i : candies) {
		numSet.insert(i);
	}

	return min(numSet.size(), candies.size() / 2);
}

int
main(int argc, char const *argv[])
{
	vector<int> v{1, 2, 3, 1, 4, 5, 6};

	cout << distribute(v) << endl;

	return 0;
}