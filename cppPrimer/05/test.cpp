#include <iostream>

using namespace std;

int
main(int argc, char const *argv[])
{
	char ch = ' ';
	char preCh = '\0';

	if (ch == preCh) {
		cout << "==" << endl;
	}
	else {
		cout << "!=" << endl;
	}

	/*
	' ' is not equal with '\0';
	'/0' is a empty char(ascii 0), but ' ' is a space char(ascii 32);
	*/

	return 0;
}