#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <set>

using namespace std;

class TextQuery {
public:
	TextQuery(ifstream &file);

	// searchString(const string &s);

private:
	vector<string> data;
	map<set<string>, vector<int>> wordMap;
};

TextQuery::TextQuery(ifstream &file)
{
	string line;
	int lineNum = 0;

	while (getline(file, line)) {
		data.push_back(line);
		++lineNum;

		// istringstream iss(line);
		// string word;
		// while (line >> word) {
		// 	wordMap[word]
		// }
	}
}

int
main(int argc, char const *argv[])
{
	ifstream file("bookList.txt");

	if (!file) {
		cout << "file open error!" << endl;
		return -1; 
	}

	TextQuery text(file);
	return 0;
}