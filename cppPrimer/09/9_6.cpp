#include <iostream>
#include <list>

using namespace std;

int
main(int argc, char const *argv[])
{
	list<int> list1{1, 2, 3};
	list<int>::iterator iter1 = list1.begin(), iter2 = list1.end();

	// error : operatpr < can only use for string&vector's iterator.
	// while (iter1 < iter2) {
	while (iter1 != iter2) {
		cout << *iter1 << endl;
		++iter1;
	}

	return 0;
}