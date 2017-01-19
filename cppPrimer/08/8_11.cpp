#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};

int
main(int argc, char const *argv[])
{
	vector<PersonInfo> vec;
	string line, word;

	// while (getline(cin, line)) {
	// 	istringstream iss(line);
	// 	if (iss) {
	// 		PersonInfo info;
	// 		iss >> info.name;
	// 		while (iss >> word) {
	// 			info.phones.push_back(word);
	// 		}
	// 		vec.push_back(info);
	// 	}
	// }

	istringstream iss;

	while (getline(cin, line)) {
		iss.clear();
	 	iss.str(line);
		if (iss) {
			PersonInfo info;
			iss >> info.name;
			while (iss >> word) {
				info.phones.push_back(word);
			}
			vec.push_back(info);
		}
	}

	for (auto i : vec) {
		cout << i.name << endl;
		for (auto j : i.phones) {
			cout << j << endl;
		}
	}

	return 0;
}