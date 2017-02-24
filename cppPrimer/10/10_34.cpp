#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <list>

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<int> vec{1, 2, 3, 4, 5, 0, 6, 7, 8, 9};

	// vector<int>::const_reverse_iterator i = vec.crbegin();

	// while (i != vec.crend()) {
	// 	cout << *i++ << endl;
	// }

	for_each(vec.crbegin(), vec.crend(), [](const int i){
		cout << i << endl;
	});

	// for (vector<int>::const_iterator j = vec.cend() - 1; j != vec.begin() - 1; --j) {
	// 	cout << *j << endl;
	// }

    for (auto iter = vec.end(); iter != vec.begin();) 
	std::cout << *--iter << " ";	

	cout << "the last zero " << *(find (vec.crbegin(), vec.crend(), 0)) << endl;

	list<int> reList;

	// copy(vec.crbegin() + 3, vec.crend() - 2, back_inserter(reList));
	copy(vec.crbegin() + 3, vec.crbegin() + 8, back_inserter(reList));

	for (auto a : reList) {
		cout << a << endl;
	}

	return 0;
}