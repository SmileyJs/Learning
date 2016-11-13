#include "chapter6.h"

int
main(int argc, char const *argv[])
{
	vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7};
	printVec(vec);
	return 0;
}

void
printVec(vector<int> &vec)
{
#ifndef NDEBUG
	cout << "size : " << vec.size() << endl;
#endif
	if (!vec.empty()) {
		auto tmp = vec.back();
		vec.pop_back();
		printVec(vec);
		cout << tmp << endl;
	}
	return;
}