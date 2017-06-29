#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
string debug_rep(const T &t)
{
	cout << __PRETTY_FUNCTION__ << endl;
	
	ostringstream ret;
	ret << t;
	
	return ret.str();
}

template <typename T>
ostream & print(ostream &os, const T &t)
{
	cout << __PRETTY_FUNCTION__ << endl;

	return os << t;
}

template <typename T, typename... Args>
ostream & print(ostream &os, const T &t, const Args&... rest)
{
	cout << __PRETTY_FUNCTION__ << endl;

	os << t << " ,";

	return print(os, rest...);
}

template <typename... Args>
ostream & errorMsg(ostream &os, const Args&... rest)
{
	cout << __PRETTY_FUNCTION__ << endl;
	
	return print(os, debug_rep(rest)...);
}

int
main(int argc, char const *argv[])
{
	errorMsg(cout, 11, "ahah", "js", 'A', true);
	return 0;
}