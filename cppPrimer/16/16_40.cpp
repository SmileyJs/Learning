#include <iostream>
#include <vector>
#include <type_traits>

using namespace std;

class Bar
{
public:
	Bar& operator+(int i) {
		cout << __PRETTY_FUNCTION__ << "\ti" <<endl;
		return *this;
	}
};

template <typename It>
auto func(It beg, It end) -> typename remove_reference<decltype(*beg + 0)>::type
{
	cout << __FUNCTION__ << __LINE__ << endl;

	return *beg;
}

int
main(int argc, char const *argv[])
{
	vector<string> v{"aaa", "bbb", "ccc", "ddd", "eee"};

	// cout << func(v.begin(), v.end()) << endl;  // to execute this, the type T of vector<T> should support operator+ with 0;

	// string s1 = "haha";
	// cout << s1 + 0 << endl;

	vector<Bar> vBar;

	vBar.push_back(Bar());
	func(vBar.begin(), vBar.end());

	return 0;
}