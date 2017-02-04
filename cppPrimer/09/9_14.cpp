#include <iostream>
#include <list>
#include <vector>

using namespace std;

int
main(int argc, char const *argv[])
{
	list<char *> l1{"111", "222", "333"};

	vector<string> v2;

	v2.assign(l1.begin(), l1.end());

	for (auto i : v2) {
		cout << i << endl;
	}

	return 0;
}