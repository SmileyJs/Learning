#include <vector>
#include <iostream>

using namespace std;

vector<int>::iterator
findInt(vector<int>::iterator begin, vector<int>::iterator end, int a) {
	for (auto i = begin; i != end; ++i) {
		if (a == *i) {
			return i;
		}
	}

	cout << "can not find it" << endl;
	return end;
}

int
main(int argc, char const *argv[])
{
	vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	if (argc != 2) {
		cout << "argument error !" << endl;
		return -1;
	}

	vector<int>::iterator iter = findInt(vec.begin(), vec.end(), stoi(argv[1]));

	if (vec.end() != iter) {
		cout << *iter << endl;
	}

	return 0;
}