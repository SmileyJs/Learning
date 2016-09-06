#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int
main(int argc, char *argv[])
{

	cout << "int: " << sizeof(int) << endl;
	cout << "char: " << sizeof(char) <<endl;
	cout << "double: " << sizeof(double) << endl;
	cout << "long: " << sizeof(long) << endl; 
	cout << "short: " << sizeof(short) << endl;
	cout << "long double: " << sizeof(long double) << endl;
	cout << "float: " << sizeof(float) << endl;

	vector<int> v;

	cout << "vector<int>: " << sizeof(v) << endl;

	v.push_back(1);
	v.push_back(2);

	cout << "vector<int>added: " << sizeof(v) << endl;

	vector<char> c;

	cout << "vector<char>: " << sizeof(c) << endl;

	int n[] = {0, 1, 2, 3, 4, 5};

	cout << "array: " << sizeof(n) << endl;

	int *p = n;

	cout << "array: " << sizeof(p) << endl;
	cout << "array pointer: " << sizeof(*p) << endl;

	return 0;
}