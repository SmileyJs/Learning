#include <iostream>

using namespace std;

template <typename T>
int compare(const T& a, const T& b)
{
	if ( a > b) 
		return 1;
	else if (a < b)
		return -1;

	return 0;
}

int
main(int argc, char const *argv[])
{
	int a = 1;
	double b = 2.0;

	cout << max<double>(a, b) << endl;

	cout << compare<const char*>("aaaaaa", "bb") << endl;

	return 0;
}