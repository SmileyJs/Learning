#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <memory>

#include "../16/DebugDelete.h"

using namespace std;

class QueryResult;

class TextQuery {
public:

	friend class QueryResult;

	explicit TextQuery(ifstream &file);

	const shared_ptr<QueryResult> query(const string &s);

	// void print(ofstream &, const string &);

private:
	shared_ptr<vector<string>> data;
	shared_ptr<map<string, set<int>>> wordMap;
};

// void
// TextQuery::print(ofstream &output, const string &word)
// {
// 	set<int> iset = wordMap->at(word);

// 	output << "element " << word << " occurs " << iset.size() << " times." << endl;

// 	for (auto i : iset) {
// 		output << "\t(line " << i << ") " << data->at(i - 1) << endl;
// 	}
// }

TextQuery::TextQuery(ifstream &file)
	// : data(make_shared<vector<string>>(), DebugDelete())
	: data(new vector<string>(), DebugDelete()) // custom deleter may not use with std::make_shared, 
	// as it has an internaldeleter which may not be replaced. As a result, keyword new is the only option to use with DebugDelete.
	, wordMap(new map<string, set<int>>(), DebugDelete())
{
	string line;
	int lineNum = 0;

	while (getline(file, line)) {
		data->push_back(line);
		++lineNum;

		istringstream iss(line);
		string word;
		while (iss >> word) {
			(*wordMap)[word].insert(lineNum);
		}
	}
}

class QueryResult {
public:
	QueryResult(const string &s, shared_ptr<set<int>> linePtr, shared_ptr<vector<string>> dataPtr)
		: word(s), lineNum(linePtr), dataPtr(dataPtr) {}

	const string & getWord() const { return word; }
	const shared_ptr<set<int>> getLineNum() const { return lineNum; }
	const shared_ptr<vector<string>> getData() const { return dataPtr; }

private:
	string word;
	shared_ptr<set<int>> lineNum;
	shared_ptr<vector<string>> dataPtr;
};

const shared_ptr<QueryResult>
TextQuery::query(const string &word)
{
	// QueryResult ret(word, make_shared<set<int>>((*wordMap)[word]), data);

	return make_shared<QueryResult>(word, make_shared<set<int>>((*wordMap)[word]), data);
}

void
print(ofstream &output, const shared_ptr<QueryResult> resultPtr)
{
	output << "element " << resultPtr->getWord() << " occurs " << resultPtr->getLineNum()->size() << " times." << endl;

	for (auto i : *(resultPtr->getLineNum())) {
		output << "\t(line " << i << ") " << resultPtr->getData()->at(i - 1) << endl;
	}
}

int
main(int argc, char const *argv[])
{
	ifstream input("BookList.txt");
	ofstream output("ouput.txt");

	if (!input) {
		cout << "input file open error!" << endl;
		return -1; 
	}

	if (!output) {
		cout << "output file open error!" << endl;
		return -1;
	} 

	TextQuery tq(input);

	// tq.print(output);

	do {
		cout << "please input the word to search, or enter q to exit" << endl;
		string word;
		if (!(cin >> word) || word == "q") 
			break;
		print(output, tq.query(word));
	}
	while (true);

	return 0;
}