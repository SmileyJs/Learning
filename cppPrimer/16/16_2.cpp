#include <iostream>
#include <vector>

#include "../07/Sales_data.h"

using namespace std;

template <typename T>
int
compare(const T& v1, const T& v2)
{
	if (v1 < v2) 
		return 1;
	if (v2 < v1)
		return -1;

	return 0;
}

template <typename InputIt, typename T>
InputIt Find(InputIt beg, InputIt end, const T& val)
{
	for (; beg != end; ++beg) {
		if (*beg == val) {
			return beg;
		}
	}

	return end;
}

int
main(int argc, char const *argv[])
{
	int a = 1, b = 3;
	vector<int> v1{2, 3}, v2{3, 4};

	cout << compare(a, b) << endl;
	cout << compare(v1, v2) << endl;

	Sales_data s1("aaa", 1, 1), s2("bbb", 1, 1);

	// compare(s1, s2);

	cout << *Find(v1.begin(), v1.end(), 3) << endl;

	return 0;
}
