#include "chapter6.h"

int
main(int argc, char const *argv[])
{
	cout << "Please input a positive number!" << endl;

	int i = 0;
	while (cin >> i && i > 0) {
		cout << "!" << i << " is " << fact(i) << endl; 
	}
	return 0;
}