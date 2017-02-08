#include <iostream>
#include <string>
#include <vector>

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<char> vec{'a', 'b', 'c', 'd', 'e'};

	string str(vec.begin(), vec.end());


	str.reserve(10);

	// for (auto i : vec) {
	// 	str.push_back(i);
	// }


	cout << str << endl
		<< "string's size "<< str.size() << endl
		<< "string's capacity " << str.capacity() << endl;

	return 0;
}