#include <iostream>
#include <list>

using namespace std;

int
main(int argc, char const *argv[])
{
	list<int> lst{0, 1, 2, 3, 4, 5};

	for(auto i = lst.begin(); i != lst.end();) {
		if (*i%2) {
			i = lst.insert(i, *i);
			advance(i, 2);
		}
		else {
			i = lst.erase(i);
		}
	}

	for (auto i : lst) {
		cout << i << endl;
	}

	return 0;
}