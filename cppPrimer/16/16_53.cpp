#include <iostream>

using namespace std;

template <typename T>
ostream& print(ostream& os, const T& t)
{
	cout << __PRETTY_FUNCTION__;

	return os << t;
}

template <typename T, typename... Args >
ostream& print(ostream& os, const T& t, const Args&... rest)
{
	cout << __PRETTY_FUNCTION__;

	os << t << endl;
	return print(os, rest...);
}

int
main(int argc, char const *argv[])
{
	print(cout, "11", 22, '3', true, "55");
	cout << endl;

	print(cout, "js");
	cout << endl;

	return 0;
}