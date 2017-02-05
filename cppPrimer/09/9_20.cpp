#include <iostream>
#include <list>
#include <deque>

using namespace std;

int
main(int argc, char const *argv[])
{
	list<int> l1{1, 2, 3, 4, 5, 6, 7};
	deque<int> odd;
	deque<int> even;

	for (auto i = l1.begin(); i != l1.end(); ++i) {
		if (*i%2 != 0) {
			odd.push_back(*i);
		}
		else {
			even.push_back(*i);
		}
	}

	cout << "the odd deque: " << endl;
	for (auto i : odd) {
		cout << i << endl;
	}

	cout << "the even deque: " << endl;
	for (auto i : even) {
		cout << i << endl;
	}

	return 0;
}