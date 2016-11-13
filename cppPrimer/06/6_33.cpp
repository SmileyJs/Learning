#include "chapter6.h"

int
main(int argc, char const *argv[])
{
	vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7};
	vectorRecursion(vec.begin(), vec.end());
	return 0;
}

void
vectorRecursion(vector<int>::iterator start, vector<int>::iterator end)
{
	// for (auto i : vec) {
	// 	cout << i << endl;
	// }

#ifndef NDEBUG
	cout << end - start << " ";
#endif
	if (start != end) {
		cout << *start << endl;
		// vectorRecursion(++start, end);
		vectorRecursion(next(start), end);
	}

}