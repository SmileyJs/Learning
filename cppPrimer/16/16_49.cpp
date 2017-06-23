#include <iostream>

using namespace std;

template <typename T>
void f(T)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

template <typename T>
void f(const T*)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

template <typename T>
void g(T)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

template <typename T>
void g(T*)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

int
main(int argc, char const *argv[])
{
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;

	g(42);
	g(i);
	g(p);
	g(ci);
	g(p2);

	f(42);
	f(i);
	f(p);
	f(ci);
	f(p2);

	return 0;
}