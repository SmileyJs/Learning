#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct PersonInfo {
	string name;
	vector<string> phoneNums;
};

bool
valid(string s) {
	if (s.length() < 4) {
		return false;
	}
	else {
		return true;
	}
}

string
format(string s) {
	return "-" + s;
}

int
main(int argc, char const *argv[])
{
	ifstream ifs("./phoneNums.txt");

	if (!ifs) {
		cout << "file open error!" << endl;
		return -1;
	}

	vector<PersonInfo> info;
	string line, word;

	while (getline(ifs, line)) {
		PersonInfo record;

		istringstream iss;
		iss.str(line);

		iss >> record.name;

		while (iss >> word) {
			record.phoneNums.push_back(word);
		}

		info.push_back(record);
	}

	for (const auto& someOne : info) {
		ostringstream formatted, badNums;

		for (const auto& nums : someOne.phoneNums) {
			if (valid(nums)) {
				formatted << " " << format(nums);
			}
			else {
				badNums << " " << nums;
			}
		}

		if (badNums.str().empty()) {
			cout << someOne.name << formatted.str() << endl;
		}
		else {
			cerr << "num error! " << someOne.name 
				<< " invalid numbers: " << badNums.str() << endl;
		}
	}



	return 0;
}