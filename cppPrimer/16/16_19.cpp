#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print1(const T& v) 
{
	typedef typename T::size_type size_type;

	for (size_type i = 0; i != v.size(); ++i) {
		cout << v[i] << endl;
	}
}

template <typename T>
void print2(const T& v)
{
	for (auto i = v.begin(); i != v.end(); ++i) {
		cout << *i << endl;
	}
}

int
main(int argc, char const *argv[])
{
	vector<string> v1{"1", "2", "3", "4", "5", "6", "7"};
	print1(v1);

	vector<int> v2{1, 2, 3, 4, 5, 6, 7};
	print1(v2);

	return 0;
}