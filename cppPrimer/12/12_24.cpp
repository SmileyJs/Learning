#include <iostream>
#include <cstring>


using namespace std;

int
main(int argc, char const *argv[])
{
	unsigned size;

	cout << "please input the size: " << endl;

	cin >> size;

	char *text = new char[size + 1]();

	cin.ignore();

	cout << "please input the string: " << endl;

	cin.get(text, size + 1);

	cout << text << endl;

	delete [] text;

	return 0;
}