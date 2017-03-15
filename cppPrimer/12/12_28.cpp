#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <fstream>

using namespace std;

int
main(int argc, char const *argv[])
{
	ifstream input("BookList.txt");

	if (!input) {
		cout << "input file error!" << endl;
		return -1;
	}

	vector<string> data;
	map<string, set<unsigned>> wordMap;

	string text;
	unsigned lineNo = 0;

	while (getline(input, text)) {
		data.push_back(text);
		++lineNo;

		istringstream lineStream(text);
		string word;
		while (lineStream >> word) {
			wordMap[word].insert(lineNo);
		}
	}

	do {
		cout << "please input the word you want to search or enter p to exit!" << endl;
		string s;
		if (!(cin >> s) || s == "q") break;

		cout << "element " << s << " occurs " << wordMap[s].size() << " times." << endl;
		for (auto i : wordMap[s]) {
			cout << "(line " << i << ")" << data.at(i - 1) << endl;
		}
	}
	while (true);

	return 0;
}