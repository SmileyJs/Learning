#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

const string &
transform(const string &s, unordered_map<string, string> const &rules) 
{
	auto iter = rules.find(s);

	if (rules.end() != iter) {
		return iter->second;
	}
	else {
		return s;
	}
}

const unordered_map<string, string>
buildMap(ifstream &rules)
{
	unordered_map<string, string> map;

	string line;
	string key;

	while (rules >> key && getline(rules, line)) {
		if (!line.empty()) {
			map[key] = line.substr(1);
		}
	}

	return map;
}

void word_transform(ifstream &input, ifstream &rules)
{
	auto map = buildMap(rules);
	string text;

	while (getline(input, text)) {
		istringstream iss(text);
		string word;
		bool bFisrt = true;

		while (iss >> word) {
			if (bFisrt) {
				bFisrt = false;
			}
			else {
				cout << " ";
			}
			cout << transform(word, map);
		}
		cout << endl;
	}
}

int
main(int argc, char const *argv[])
{
	ifstream input("input.txt");
	ifstream rules("map_file.txt");

	if (input && rules) {
		word_transform(input, rules);
	}

	return 0;
}