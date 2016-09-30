#include "chapter6.h"

int
main(int argc, char const *argv[])
{
	int i =0, j = 0;
	cout << "Please input two positive integer" << endl;

	while (cin >> i >> j) {
		cout << "The bigger one is " << compareInt(i, &j) << endl;
	}

	return 0;
}

int compareInt(const int j, const int *p) 
{
	return j > *p ? j : *p;
} 