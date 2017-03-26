#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include "StrVec.h"

using namespace std;

class QueryResult;

class QueryText {
public:
	QueryText(ifstream &);
	QueryResult query(const string &);
	void print(ofstream &);

private:
	shared_ptr<StrVec> pData;
	map<string, shared_ptr<set<unsigned>>> wordMap;
};

QueryText::QueryText(ifstream &input)
	: pData(make_shared<StrVec>())
{
	unsigned lineNo = 0;
	string line;

	while (getline(input, line)) {
		pData->push_back(line);
		++lineNo;

		istringstream lineStream(line);
		string word;
		while (lineStream >> word) {
			// reference, if res get null, new object will not insert into wordmap.
			shared_ptr<set<unsigned>> &res = wordMap[word];

			if (!res) {
				res.reset(new set<unsigned>());
			}
			else {
				res->insert(lineNo);
			}
		}
	}
}

class QueryResult {
public:
	friend void print(ofstream &, const QueryResult &);

	QueryResult(const string &s, shared_ptr<set<unsigned>> pLine, shared_ptr<StrVec> pInput)
		: word(s), pLineNos(pLine), pData(pInput) {}
private:
	string word;
	shared_ptr<set<unsigned>> pLineNos;
	shared_ptr<StrVec> pData;
};

QueryResult
QueryText::query(const string &word) {
	shared_ptr<set<unsigned>> nodata = make_shared<set<unsigned>>();
	auto found = wordMap.find(word);

	if (found == wordMap.end()) {
		return QueryResult(word, nodata, pData);
	}
	else {
		return QueryResult(word, found->second, pData);
	}
}

void
QueryText::print(ofstream &output)
{
	for (auto i : wordMap) {
		output << i.first << ": " << endl;
		for (auto j : *(i.second)) {
			output << j << " ";
		}
	}
}

void
print(ofstream &output, const QueryResult &result)
{
	output << "element " << result.word << " occurs " << result.pLineNos->size() << " times." << endl;

	for (auto i : *(result.pLineNos)) {
		output << "\t(line " << i << ") " << result.pData->at(i - 1) << endl;
	}
}

int
main(int argc, char const *argv[])
{
	ifstream input("BookList.txt");
	ofstream output("output.txt");

	if (!input) {
		cout << "input file open error!" << endl;
		return -1;
	}

	if (!output) {
		cout << "output file open error!" << endl;
		return -1;
	}

	QueryText qt(input);
	string word;

	do {
		cout << "please input the word for searching or p to exit!" << endl;
		if (!(cin >> word) || word == "q") break;
		print(output, qt.query(word));
	}
	while (true);

	return 0;
}