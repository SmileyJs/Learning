#include <algorithm>
#include <iostream>

using namespace std;

int
main(int argc, char const *argv[])
{
	if (2 != argc) {
		cout << "argument error!" << endl;
		return -1;
	}

	vector<int> vec{1, 2, 1, 3, 1, 4, 1, 4, 1, 3, 2, 1};

	auto i = count(vec.begin(), vec.end(), stoi(argv[1]));

	cout << argv[1] << " appears " << i << " times!" << endl;

	return 0;
}