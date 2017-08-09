#include <iostream>

using namespace std;

class Base
{
	int i = 1;
public:

// protected:
	Base() {
		cout << "Base constructor" << endl;
	}
};

void func(int i)
{
	static Base b;
	cout << "i= " << i << endl;
}

int
main(int argc, char const *argv[])
{
	func(1);
	func(2);
	return 0;
}