#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

int
main(int argc, char const *argv[])
{
	if (2 != argc) {
		cout << "argument error!" << endl;
		return -1;
	}

	ifstream ifs(argv[1]);

	if (!ifs) {
		cout << "file open error!" << endl;
		return -2;
	}

	vector<string> vec;
	string line, word;
	while (getline(ifs, line)) {
		vec.push_back(line);
	}

	for (string s : vec) {
		istringstream iss(s);
		while (iss >> word) {
			cout << word << endl;
		}
		cout << s << endl;
	}

	return 0;
}