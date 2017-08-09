#include <iostream>

using namespace std;

bool
PowerOfTwo(int n)
{
	return n > 0 && !(n&(n-1));
}

int
main(int argc, char const *argv[])
{
	int i;
	while (cin >> i) {
		cout << i << "'s result of PowerOfTwo is " << PowerOfTwo(i) << endl;
	}

	return 0;
}