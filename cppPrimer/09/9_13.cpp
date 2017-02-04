#include <iostream>
#include <vector>
#include <list>

using namespace std;

int
main(int argc, char const *argv[])
{
	list<int> v1{1, 2, 3, 4, 5};

	vector<double> v2(v1.begin(), v1.end());

	vector<int> v3{1, 2, 3, 4, 5};

	vector<double> v4(v3.begin(), v3.end());

	for (auto i : v1) cout << i;
	cout << endl;

	for (auto i : v2) cout << i;
	cout << endl;

	for (auto i : v3) cout << i;
	cout << endl;

	for (auto i : v4) cout << i;
	cout << endl;

	return 0;
}