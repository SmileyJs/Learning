#include <iostream>

using namespace std;

// void
// call0()
// {
// 	cout << maxInt(1, 2) << endl;
// }

void
call1()
{
	int maxInt(int, int);
	cout << maxInt(1, 2) << endl;
}

int
main(int argc, char const *argv[])
{
	// call0();
	call1();
	
	return 0;
}

int
maxInt(int x, int y)
{
	cout << __PRETTY_FUNCTION__ << x << y << endl;
	return x > y ? x : y;
}