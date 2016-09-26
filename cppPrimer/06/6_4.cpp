#include <iostream>

using namespace std;

int fact(int i);

int
main(int argc, char const *argv[])
{
	cout << "Please input a positive number!" << endl;

	int i;

	while (cin >> i && i > 0) {
		int j = fact(i);
		cout << i << "! is " << j << endl;
	}

	return 0;
}

int 
fact(int i)
{
	if (i > 1)
		return i * fact(i-1);
	else
		return 1;
}