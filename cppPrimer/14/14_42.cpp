#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<int> vInt{1, 2, 111, 333, 444, 22};

	vector<string> vStr{"aaa", "bbb", "ccc", "ddd", "eee", "fff"};

	auto cntInt = count_if(vInt.begin(), vInt.end(), bind(greater<int>(), placeholders::_1, 11));

	cout << "There are " << cntInt << " integers big than 11." << endl;

	auto res = find_if(vStr.begin(), vStr.end(), bind(equal_to<string>(), placeholders::_1, "bbb"));

	cout << *res << endl;

	transform(vInt.begin(), vInt.end(), vInt.begin(), bind(multiplies<int>(), placeholders::_1, 2));

	for (auto i : vInt) {
		cout << i << endl;
	}

	return 0;
}