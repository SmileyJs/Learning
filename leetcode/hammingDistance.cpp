#include <iostream>

using namespace std;

int
distance(int x, int y)
{
    if ((x ^ y) == 0) 
    	return 0;
    return (x ^ y) % 2 + distance(x/2, y/2);
}

int
main(int argc, char const *argv[])
{
	cout << "please input two integer: ";

	int i, j;

	cin >> i >> j;

	cout << distance(i, j) << endl;

	return 0;
}