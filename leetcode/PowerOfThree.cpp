#include <iostream>

using namespace std;

bool
PowerOfThree(int num)
{
	// if (num < 1)
	// 	return false;

	// while (0 == num % 3)
	// 	num /= 3;

	// return 1 == num;

	return fmod(log(num)/log(3), 1) == 0;
}

int
main(int argc, char const *argv[])
{
	int i;

	while (cin >> i) {
		cout << i << "'s result of PowerOfThree is " << PowerOfThree(i) << endl;
	}

	return 0;
}