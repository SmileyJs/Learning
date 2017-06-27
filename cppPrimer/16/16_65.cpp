#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
string debug_rep(const T &t)
{
	cout << __PRETTY_FUNCTION__ << endl;

	ostringstream os;

	os << t;

	return os.str();
}

template <typename T>
string debug_rep(T *p)
{
	cout << __PRETTY_FUNCTION__ << endl;

	ostringstream os;

	os << "pointer: " << p;

	if (p) {
		os << " " << debug_rep(*p);
	}
	else {
		os << "null pointer.";
	}

	return os.str();
}

template <>
string debug_rep(char *p)
{
	cout << __PRETTY_FUNCTION__ << endl;

	return string(p);
}
 	
template <>
string debug_rep(const char *p)
{
	cout << __PRETTY_FUNCTION__ << endl;

	return string(p);
}

int
main(int argc, char const *argv[])
{
	string s("haha");
	cout << debug_rep(&s) << endl;

	cout << debug_rep("haha") << endl;	

	const char *p = "alan"; // string == const char* ??
	cout << debug_rep(p) << endl;

	char a[] = "walker";
	cout << debug_rep(a) << endl;

	return 0;
}