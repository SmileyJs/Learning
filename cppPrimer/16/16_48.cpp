#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
string debug_rep(const T& t)
{
	cout << __PRETTY_FUNCTION__ << endl;

	ostringstream ret;
	ret << t;

	return ret.str();
}

template <typename T>
string debug_rep(T* p)
{
	cout << __PRETTY_FUNCTION__ << endl;

	ostringstream ret;

	ret << p << " ";

	if (p) {
		ret << debug_rep(*p);
	}
	else {
		ret << "p is a nullptr";
	}

	return ret.str();
}

string debug_rep(const string &s)
{
	cout << __PRETTY_FUNCTION__ << endl;

	return '"' + s + '"';
}

string debug_rep(char* p)
{
	cout << __PRETTY_FUNCTION__ << endl;

	return debug_rep(string(p));
}

string debug_rep(const char* p)
{
	cout << __PRETTY_FUNCTION__ << endl;

	return debug_rep(string(p));
}

int
main(int argc, char const *argv[])
{
	string s("hi");

	cout << debug_rep(s) << endl;
	cout << debug_rep(&s) << endl;
	cout << debug_rep("hi") << endl;

	return 0;
}