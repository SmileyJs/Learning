#include <vector>
#include <iostream>

using namespace std;

bool
findInt(vector<int>::iterator begin, vector<int>::iterator end, int a) {
	for (auto i = begin; i != end; ++i) {
		if (a == *i) {
			return true;
		}
	}

	return false;
}

int
main(int argc, char const *argv[])
{
	vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	if (argc != 2) {
		cout << "argument error !" << endl;
		return -1;
	}

	cout << stoi(argv[1]) << endl;

	if (findInt(vec.begin(), vec.end(), stoi(argv[1])))  {
		cout << "Got it" << endl;
	}
	else {
		cout << "can not find it" << endl;
	}

	return 0;
}