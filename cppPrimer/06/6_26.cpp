#include "chapter6.h"

int
main(int argc, char const *argv[])
{
	cout << numberSum({1, 2, 3, 4, 5}) << endl;
	cout << numberSum({1, 2, 3, 4, 5, 6}) << endl;
	return 0;
}

int numberSum(initializer_list<int> list)
{
	int sum = 0;
	for (auto i : list) {
		sum += i;
	}
	return sum;
}