#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

map<string, string>
build_map(ifstream& rules)
{
	map<string, string> ruleMap;
	string word;
	string line;

	while (rules >> word && getline(rules, line)) {
		if (!line.empty()) {
			// 11_35: word appear multiple times case.
			// use subscript operate: will put the last correspond phrase into map.
			// use insert: will put the fisrt correspond phrase into map.
			ruleMap.insert({word, line.substr(1)});
			// ruleMap[word] = line.substr(1);
		}
	}

	return ruleMap;
}

const string&
transform(const map<string, string> &rules, const string &s)
{
	auto iter = rules.find(s);

	// 11_34: sub script version. error: is map has no key "s", will create an element key is 's';
	// besides, the map is constant, will occur compile error. 
	// auto iter = rules[s];

	if (iter != rules.end()) {
		return iter->second;
	}
	else {
		return s;
	}
}

void
word_transform(ifstream &input, ifstream &rules)
{
	map<string, string> trans_map = build_map(rules);

	string word;

	// jsssssss version: no line break
	// while (input >> word) {
	// 	cout << transform(trans_map, word) << " ";
	// }
	// cout << endl;

	string line;

	while (getline(input, line)) {
		istringstream iss(line);
		bool bFirst = true;
		while (iss >> word) {
			if (bFirst) {
				bFirst = false;
			}
			else {
				cout << " ";
			}
			cout << transform(trans_map, word);
		}
		cout << endl;
	}
}


int
main(int argc, char const *argv[])
{
	ifstream ifs_rule("rules.txt");
	ifstream ifs_input("input.txt");

	if (ifs_rule && ifs_input)
		word_transform(ifs_input, ifs_rule);

	return 0;
}