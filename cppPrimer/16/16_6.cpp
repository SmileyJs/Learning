#include <iostream>

using namespace std;

template <typename T, unsigned sz>
T*
begin(const T (&array)[sz])
{
	return array;
}

template <typename T, unsigned sz>
T*
end(const T (&array)[sz])
{
	return array + sz;
}

template <typename T, unsigned sz>
unsigned
sizeOfArray(const T (&array)[sz])
{
	return sz;
}

int
main(int argc, char const *argv[])
{
	int a[5] = {1, 2, 3, 4, 5};

	cout << begin(a) << endl;
	cout << end(a) << endl;
	cout << sizeOfArray(a) << endl;

	return 0;
}