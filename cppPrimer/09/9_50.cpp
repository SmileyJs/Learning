#include <iostream>
#include <string>
#include <vector>

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<string> intergers{"11", "34", "23", "56", "15"};

	int int_sum = 0;

	for (auto i : intergers) {
		int_sum += stoi(i);
	}

	cout << "intergers' sum is " << int_sum << endl;

	vector<string> floats{"11.1", "34.1", "23.1", "56.1", "15.1"};

	float float_sum = 0;

	for (auto i : floats) {
		float_sum += stof(i);
	}

	cout << "floats' sum is " << float_sum << endl;

	return 0;
}