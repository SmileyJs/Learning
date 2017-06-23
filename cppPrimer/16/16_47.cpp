#include <iostream>
#include <utility>

using namespace std;

void f(int i, int& j)
{
	cout << __PRETTY_FUNCTION__ << endl;

	cout << i << " " << ++j << endl;
}

void g(int&& i, int& j)
{
	cout << __PRETTY_FUNCTION__ << endl;

	cout << i << " " << ++j << endl;
}

template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2)
{
	cout << __PRETTY_FUNCTION__ << endl;

	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

template <typename F, typename T1, typename T2>
void flip2(F f, T1 t1, T2 t2)
{
	cout << __PRETTY_FUNCTION__ << endl;

	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int
main(int argc, char const *argv[])
{
	int i = 41;

	flip(f, i, 42);
	cout << i << endl;

	flip(g, i, 43);
	cout << i << endl;
	
	return 0;
}