#include <iostream>
#include <vector>

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<int> v1{1, 2, 3, 4, 5};
	vector<int> v2{1, 2, 3, 4, 5};
	vector<int> v3{1, 2, 3, 4, 5, 6};
	vector<int> v4{2};

	if (v1 == v2) {
		cout << "v1 == v2" << endl;
	}
	else if (v1 < v2) {
		cout << "v1 < v2" << endl;
	}
	else {
		cout << "v1 > v2" << endl;
	}

	if (v1 == v3) {
		cout << "v1 == v3" << endl;
	}
	else if (v1 < v3) {
		cout << "v1 < v3" << endl;
	}
	else {
		cout << "v1 > v3" << endl;
	}

	if (v1 == v4) {
		cout << "v1 == v4" << endl;
	}
	else if (v1 < v4) {
		cout << "v1 < v4" << endl;
	}
	else {
		cout << "v1 > v4" << endl;
	}


	return 0;
}