#include <iostream>

using namespace std;

int absValue(int i);

int
main(int argc, char const *argv[])
{
	int i = 0;
	cout << "Please input a number!" << endl;
	while (cin >> i) {
		cout << i << "'s absolute number is " << absValue(i) <<  endl;;
	}
	return 0;
}

int absValue(int i)
{
	return i >= 0 ? i : -i; 
}