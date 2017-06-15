#include <iostream>

using namespace std;

template <typename T> 
void f1(T, T)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

template <typename T1, typename T2>
void f2(T1, T2)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

int
main(int argc, char const *argv[])
{
	int i = 0, j = 42, *p1 = &i, *p2 = &j;
	const int *cp1 = &i, *cp2 = &j;

	f1(p1, p2);
	f2(p1, p2);

	f1(cp1, cp2);
	f2(cp1, cp2);

	// f1(p1, cp1); // error int* vs const int*
	f2(p1, cp1);

	return 0;
}