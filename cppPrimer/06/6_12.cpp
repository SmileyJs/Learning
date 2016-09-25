#include "chapter6.h"

int
main(int argc, char const *argv[])
{
	cout << "Please input two number!" << endl;
	int i = 0;
	int j = 0;

	cin >> i >> j;
	cout << "The input numbers are " << i << " and " << j << endl;

	swapRef(i, j);
	cout << "After swapRef are " << i << " and " << j << endl;

	return 0;
}

void
swapRef(int &i, int &j)
{
	int tmp = i;
	i = j;
	j = tmp;
}