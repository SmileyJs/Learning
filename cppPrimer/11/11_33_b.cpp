#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

const string & 
transform(const map<string, string> &rules_map, const string &s)
{
	auto iter = rules_map.find(s);

	if (rules_map.end() != iter) {
		return iter->second;
	}
	else {
		return s;
	}
}

map<string, string>
build_map(ifstream &rules)
{
	map<string, string> rules_map;

	string word;
	string text;

	while (rules >> word && getline(rules, text)) {
		if (!text.empty()) {
			rules_map[word] = text.substr(1);
		}
	}

	return rules_map;
}

void word_transform(ifstream &input, ifstream &rules)
{
	map<string, string> rules_map = build_map(rules);

	string word;
	string line;

	while(getline(input, line)) {
		istringstream iss(line);
		bool bFirst = true;
		while (iss >> word) {
			if (bFirst) {
				bFirst = false;
			}
			else {
				cout << " ";
			}
			cout << transform(rules_map, word);
		}
		cout << "|" << endl;
	}
}

int
main(int argc, char const *argv[])
{
	ifstream ifs_rules("map_file.txt");
	ifstream ifs_input("input.txt");

	if (ifs_rules && ifs_input) 
		word_transform(ifs_input, ifs_rules);

	return 0;
}