#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int
main(int argc, char const *argv[])
{
	vector<int> v;

	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
	}

	// for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
	// 	*i = (0 == (*i)%2) ? *i : (*i)*2;
	// }	

	// for (auto i = v.begin(); i != v.end(); ++i) {
	// 	cout << *i << endl;
	// }

//*********better
	for (auto &i : v) {
		i = (i % 2) ? i*2 : i;
	}

	for (auto i : v) {
		cout << i << endl;
	}

	return 0;
}