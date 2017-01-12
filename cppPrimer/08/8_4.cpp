#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void ReadFileToVec(const string &fileName, vector<string> &vstr) 
{
	ifstream ifs(fileName);
	if (ifs) {
		string str = "";
		while (getline(ifs, str)) {
			vstr.push_back(str);
		}
	}
}

int
main(int argc, char const *argv[])
{
	// cout << "AA" << endl;
	// cout << "AA" << flush;
	// cout << "AA" << ends;

	vector<string> vecStr;

	ReadFileToVec("read.txt", vecStr);

	for (const string &str : vecStr) {
		cout << str << endl;
	}

	return 0;
}