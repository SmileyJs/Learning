#include <list>
#include <vector>
#include <iostream>

using namespace std;

int
main(int argc, char const *argv[])
{
	list<int> l1{1, 2, 3, 4, 5};
	vector<int> v1{1, 2, 3, 4, 5};
	vector<int> v2{2, 3, 4};
	vector<int> v3{1, 2, 3, 4, 5, 6};

	if (vector<int>(l1.begin(), l1.end()) == v1) {
		cout << "v1 == l1" << endl;
	}
	else if (vector<int>(l1.begin(), l1.end()) < v1) {
		cout << "l1 < v1" << endl;
	}
	else {
		cout << "l1 > v1" << endl;
	}

	if (vector<int>(l1.begin(), l1.end()) == v2) {
		cout << "v2 == l1" << endl;
	}
	else if (vector<int>(l1.begin(), l1.end()) < v2) {
		cout << "l1 < v2" << endl;
	}
	else {
		cout << "l1 > v2" << endl;
	}

	if (vector<int>(l1.begin(), l1.end()) == v3) {
		cout << "v3 == l1" << endl;
	}
	else if (vector<int>(l1.begin(), l1.end()) < v3) {
		cout << "l1 < v3" << endl;
	}
	else {
		cout << "l1 > v3" << endl;
	}

	return 0;
}