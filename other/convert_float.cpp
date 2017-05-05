#include <iostream>

using namespace std;

int
main(int argc, char const *argv[])
{
	float a = 1.0f;
	cout << (int)a << endl;
	cout << &a << endl;
	cout << (int&)a << endl;
	cout << boolalpha << ((int)a == (int&)a) << endl;
	int c = (int)a;
	int &d = c;
	cout << d << endl;

	float b = 0.0f;
	cout << (int)b << endl;
	cout << &b << endl;
	cout << (int&)b << endl;
	cout << boolalpha << ((int)b == (int&)b) << endl;

	return 0;
}