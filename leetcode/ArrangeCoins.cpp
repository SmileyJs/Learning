#include <iostream>
#include <cmath>

using namespace std;

int arrangeCoins1(int x)
{
	int ret = 0;
	int line = 1;

	while ((x -= line) >= 0) {
		++ret;
		++line;
	}

	return ret;
}

int arrangeCoins2(int x)
{
	return floor(sqrt(2*long(x) + 1/4.0) - 1/2.0);
}

int arrangeCoins3(int x)
{
	int line = 1;

	for (int sum = 0; sum <= x; ++line) {
		sum += line;
	}

	return max(line - 2, 0);
}

void print(int x) 
{
	int tmp = x;
	for (int i = 1; (tmp -= i) >= 0; ++i) {
		for (int j = 0; j < i; ++j) {
			cout << 'o';
		}
		cout << endl;
		x = tmp;
	}	
	for (int j = 0; j < x; ++j) {
		cout << 'o';
	}
	cout << endl;
}

int
main(int argc, char const *argv[])
{
	int i;
	cin >> i;

	print(i);

	cout << "1: " << arrangeCoins1(i) << endl;
	cout << "2: " << arrangeCoins2(i) << endl;
	cout << "3: " << arrangeCoins3(i) << endl;

	return 0;
}