#include <algorithm>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<int> vec{1, 2, 3, 4, 5};

	int sum = accumulate(vec.begin(), vec.end(), 0);

	cout << "sum is " << sum << endl;

	return 0;
}