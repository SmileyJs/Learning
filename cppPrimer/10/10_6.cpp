#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<int> vec{1, 2, 3, 4, 5};

	fill_n(vec.begin(), vec.size(), 0);

	for (auto i : vec) {
		cout << i << endl;	
	}

	return 0;
}