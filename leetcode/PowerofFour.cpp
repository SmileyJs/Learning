#include <iostream>

using namespace std;

bool
PowerOfFour(int num)
{
	return num > 0 && !(num&(num-1)) && (num & 0x55555555);
}

int
main(int argc, char const *argv[])
{
	int i;

	while (cin >> i) {
		cout << i << "'s result of PowerOfFour is " << PowerOfFour(i) << endl;
	}

	return 0;
}