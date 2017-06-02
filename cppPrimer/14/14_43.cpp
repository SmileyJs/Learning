#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int
main(int argc, char const *argv[])
{
	cout << "Please input a integer: " << endl;

	vector<int> vec{10, 15, 20, 40};
	int input;

	cin >> input;

	modulus<int> mod;

	auto ret = all_of(vec.begin(), vec.end(), [&](int i)->bool { return 0 == mod(i, input); });
	
	if(!ret) {
		cout << input << " isn't divisible by any elements." << endl;
		return -1;
	}

	cout << input << " is divisible by any elements." << endl;

	return 0;
}