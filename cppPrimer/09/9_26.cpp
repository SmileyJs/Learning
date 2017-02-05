#include <iostream>
#include <vector>
#include <list>

using namespace std;

int
main(int argc, char const *argv[])
{
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	
	vector<int> iVec(ia, end(ia));
	list<int> iList(ia, end(ia));

	for (auto i = iList.begin(); i != iList.end();) {
		if (*i%2) {
			++i;
		}
		else {
			i = iList.erase(i);
		}
	}

	for (auto i = iVec.begin(); i != iVec.end();) {
		if (*i%2) {
			i = iVec.erase(i);
		}
		else {
			++i;	
		}
	}

	cout << "print even num: " << endl;
	for (auto i : iList) {
		cout << i << endl;
	}

	cout << "print odd num: " << endl;
	for (auto i : iVec) {
		cout << i << endl;
	}

	return 0;
}