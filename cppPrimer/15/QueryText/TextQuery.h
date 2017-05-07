#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <set>
#include <map>

using namespace std;

class QueryResult;

class TextQuery
{
public:
	TextQuery(ifstream&);
	QueryResult query(const string&) const;

private:
	shared_ptr<vector<string>> pData;
	map<string, shared_ptr<set<unsigned>>> wordMap;	
};

class QueryResult
{
public:
	friend void print(ostream&, const QueryResult&);
	QueryResult(const string& s,shared_ptr<set<unsigned>> pLine, shared_ptr<vector<string>> data)
		: word(s), pLineNos(pLine), pData(data) {}

private:
	string word;
	shared_ptr<set<unsigned>> pLineNos;
	shared_ptr<vector<string>> pData;
};

TextQuery::TextQuery(ifstream& input)
	: pData(make_shared<vector<string>>())
{
	unsigned lineNo = 0;
	string line;

	while (getline(input, line)) {
		pData->push_back(line);
		++ lineNo;

		istringstream lineStream(line);
		string word;

		while (lineStream >> word) {
			shared_ptr<set<unsigned>> &res = wordMap[word];

			if (!res) {
				res.reset(new set<unsigned>());
			}
			res->insert(lineNo);
		}
	}
}

QueryResult
TextQuery::query(const string& s) const
{
	shared_ptr<set<unsigned>> noData = make_shared<set<unsigned>>();
	auto found = wordMap.find(s);

	if (found == wordMap.end()) {
		return QueryResult(s, noData, pData);
	}
	else {
		return QueryResult(s, found->second, pData);
	}
}

void
print(ostream& os, const QueryResult& result)
{
	for (auto i : *(result.pLineNos)) {
		os << "line" << i << result.pData->at(i-1) << endl;
	}
}

#endif