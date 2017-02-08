#include <iostream>
#include <vector>

using namespace std;

int
main(int argc, char const *argv[])
{
	if (argc != 2) {
		cout << "argument error!" << endl;
		return -1;
	}

	vector<int> vec;
	vec.reserve(1024);

	for (int i = 0; i < atoi(argv[1]); ++i) {
		vec.push_back(i);
	}

	vec.resize(vec.size() + vec.size()/2);

	cout << "vector's size is " << vec.size() << endl 
		<< "vector's capacity is " << vec.capacity() << endl;

	return 0;
}