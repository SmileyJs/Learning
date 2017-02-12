#include <iostream>
#include <fstream>

using namespace std;

int
main(int argc, char const *argv[])
{
	ifstream ifs("./word.txt");

	if (!ifs) {
		cout << "file open error!" << endl;
		return -1;
	}

	string record, tmp;

	while (ifs >> tmp) {
		if (tmp.find_first_not_of("aceimnorsuvwxz") == string::npos && record.size() <= tmp.size()) {
			record = tmp;
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