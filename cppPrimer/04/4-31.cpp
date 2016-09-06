#include <iostream>
#include <vector>

using std::vector;
using std::endl;
using std::cout;

int
main(int argc, char *argv[])
{
	vector<int> ivec(10, 1);

	vector<int>::size_type cnt = ivec.size();

	for (vector<int>::size_type i = 0; i != ivec.size(); i++, cnt--) {
		ivec[i] = cnt;
	}

	for (auto i : ivec) {
		cout << i << endl;
	}

	return 0;
}