#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <fstream>

using namespace std;

int
main(int argc, char const *argv[])
{
	if (4 != argc) {
		cout << "argument error!" << endl;
		return -1;
	}

	ifstream ifs(argv[1]);
	ofstream odd_os(argv[2], ofstream::app);
	ofstream even_os(argv[3], ofstream::app);

	if (!(ifs && odd_os && even_os)) {
		cout << "file operate errpr!" << endl;
		return -2;
	}

	istream_iterator<int> in(ifs), eof;

	ostream_iterator<int> odd_iter(odd_os, " ");
	ostream_iterator<int> even_iter(even_os, "\n");

	while (in != eof) {
		if (*in % 2) {
			*odd_iter++ = *in;
		}
		else {
			*even_iter++ = *in;
		}
		++in;
	}

	return 0;
}