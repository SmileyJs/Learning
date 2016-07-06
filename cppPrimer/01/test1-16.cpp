#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "Please input some number:" << endl;

	int sum = 0;
	int value = 0;

	while (cin >> value) {
		sum += value;
	}

	cout << "Sum of these numbers is " << sum << endl;
	return 0;
}