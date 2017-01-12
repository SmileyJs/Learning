#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void
readWordFromFile(const string &fileName, vector<string> &vec) 
{
	ifstream ifs(fileName);

	if (ifs) {
		string str = "";
		while (ifs >> str) {
			vec.push_back(str);
		}
	}
}

int
main(int argc, char const *argv[])
{
	vector<string> vec;

	readWordFromFile("read.txt", vec);

	for (const auto &str : vec) {
		cout << str << endl;
	}

	return 0;
}