#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

int
main(int argc, char const *argv[])
{
	ifstream ifs("./data.txt");

	if (!ifs) {
		cout << "file open error!" << endl;
		return -1;
	}

	istream_iterator<string> in_iter(ifs), eof;

	vector<string> vec;

	copy(in_iter, eof, back_inserter(vec));

	for (auto i : vec) {
		cout << i << endl;
	}

	return 0;
}