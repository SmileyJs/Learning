#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>

using namespace std;

int
main(int argc, char const *argv[])
{
	istream_iterator<int> in_iter(cin), eof;
	ostream_iterator<int> out_iter(cout, "\n");

	// vector<int> vec(in_iter, eof);
	vector<int> vec;

	while (in_iter != eof) {
		vec.push_back(*in_iter++);
	}

	copy(vec.begin(), vec.end(), out_iter);

	sort(vec.begin(), vec.end());

	unique_copy(vec.begin(), vec.end(), out_iter);

	return 0;
}