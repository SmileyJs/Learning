#include <iostream>

using namespace std;

int fact(int i);

int
main(int argc, char const *argv[])
{
	cout << "5! is " << fact(5) << endl;
	return 0;
}

int fact(int i)
{
	int ret = 1;

	while (i > 1) {
		ret *= i;
		--i;
	}

	return ret;
}