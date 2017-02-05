#include <iostream>
#include <vector>

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<string> v1{"jsssssss", "hello", "kitty"};

	cout << v1.at(1) << endl;
	cout << v1[1] << endl;
	cout << *(v1.begin()) << endl; // iterator
	cout << (v1.front()) << endl; // reference

	return 0;
}