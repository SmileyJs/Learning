#include <iostream>
#include <string>
#include <fstream>
#include <string>

using namespace std;

bool 
findAscender(const string &s) {
	string ascender("bdfhklt");

	if (string::npos == s.find_first_of(ascender)) {
		return false;
	}
	else {
		return true;
	}
}

bool 
findDescender(const string &s) {
	string descender("gjpqy");

	if (string::npos == s.find_first_of(descender)) {
		return false;
	}
	else {
		return true;
	}
}


int
main(int argc, char const *argv[])
{
	string record, tmp;

	ifstream ifs("./word.txt");
	if (!ifs) {
		cout << "file open error!" << endl;
		return -1;
	}

	while (getline(ifs, tmp)) {
		if (!findAscender(tmp) && !findDescender(tmp)) {
			if (record.size() < tmp.size()) record = tmp;
		}
	}

	if ("" == record) {
		cout << "There is no meet the requirement!" << endl;
	}
	else {
		cout << "The longest word is "<< record << endl;
	}

	return 0;
}