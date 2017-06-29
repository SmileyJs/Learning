#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int count(const vector<T> &v, const T &t)
{
	cout << __PRETTY_FUNCTION__ << endl;

	int ret = 0;

	for (auto i : v) {
		if (i == t) 
			++ret;
	}

	return ret;
}

template < >
int count(const vector<const char*> &v, const char* const &t)
{
	cout << __PRETTY_FUNCTION__ << endl;

	int ret = 0;

	for (auto i : v) {
		if (*t == *i)
			++ret;
	}

	return ret;
}

int
main(int argc, char const *argv[])
{
	vector<int> a{1, 2, 3, 4, 1, 6, 7};
	cout << count(a, 1) << endl;

	vector<double> b{1.1, 2.2, 3.3, 1.1, 2, 3.3};
	cout << count(b, 3.3) << endl;

	vector<string> c{"aa", "bb", "cc", "dd", "aa", "aa", "bb"};
	cout << count(c, string("dd")) << endl;

	vector<const char*> d{"aa", "bb", "cc", "ddd", "aa", "aa", "bb"};
	const char *p = "aa";
	cout << count(d, p) << endl;

	return 0;
}