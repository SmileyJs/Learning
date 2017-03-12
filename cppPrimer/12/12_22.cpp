#include "StrBlob.h"
#include <fstream>

using namespace std;

int
main(int argc, char const *argv[])
{
	ifstream ifs("input.txt");

	if (!ifs) {
		cout << "file open error!" << endl;
		return -1;
	}

	string line;
	vector<string> vec;

	while (getline(ifs, line)) {
		vec.push_back(line);
	}

	StrBlob str(vec);

	for (auto pbeg = str.begin(), pend = str.end(); pbeg != pend; pbeg.incr()) {
		cout << pbeg.deRef() << endl;
	}

	return 0;
}