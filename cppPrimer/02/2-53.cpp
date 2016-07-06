#include <iostream>

using namespace std;

int main(void)
{
	int a = 3, b = 4;

	decltype (a) c = a;
	decltype ((b)) d = a;
	decltype (a = b) e = a;

	++c;
	++d;

	cout << "a = " << a << ", b = " << b << ", e = " << e << endl;
	
	return 0;
}
