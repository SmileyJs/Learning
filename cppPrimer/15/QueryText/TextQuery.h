#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <set>
#include <map>
#include <iterator>

using namespace std;

class QueryResult;

class TextQuery
{
public:
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
	shared_ptr<vector<string>> handlePunct(const string& s) const;

private:
	shared_ptr<vector<string>> pData;
	map<string, shared_ptr<set<unsigned>>> wordMap;	
};

class QueryResult
{
public:
	friend void print(ostream&, const QueryResult&);
	friend void print(ostream&, const QueryResult&, size_t, size_t);
	QueryResult(const string& s,shared_ptr<set<unsigned>> pLine, shared_ptr<vector<string>> data)
		: word(s), pLineNos(pLine), pData(data) {}

	set<unsigned>::iterator begin() const { return pLineNos->begin(); }
	set<unsigned>::iterator end() const { return pLineNos->end(); }

	const shared_ptr<vector<string>> getFile() const { return pData; }

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
			auto str = handlePunct(word);

			for (auto s : *str) {
				shared_ptr<set<unsigned>> &res = wordMap[s];

				if (!res) {
					res.reset(new set<unsigned>());
				}
				res->insert(lineNo);

				cout << s << " " << lineNo << endl;
			}
		}
	}
}

shared_ptr<vector<string>>
TextQuery::handlePunct(const string& s) const
{
	shared_ptr<vector<string>> p = make_shared<vector<string>>();

	size_t first = 0, index = 0;

	while (index != s.size()) {
		if (ispunct(s[index])) {
			string word = s.substr(first, index - first);
			if (!word.empty()) 
				p->push_back(word);

			p->push_back(s.substr(index, 1));

			++ index;
			first = index;
		} 
		else {
			++ index;
		}
	}

	string trail = s.substr(first);
	if (! trail.empty())
		p->push_back(trail);

	return p;
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
	os << __PRETTY_FUNCTION__ << endl;
	for (auto i : *(result.pLineNos)) {
		os << "line: " << i << " " << result.pData->at(i-1) << endl;
	}
}

void
print(ostream& os, const QueryResult& result, size_t beg, size_t end)
{
	os << __PRETTY_FUNCTION__ << endl;

	if (end < beg) {
		cout << "illegal range!" << endl;
	}
	else {
		for (auto i : *(result.pLineNos)) {
			if (i >= beg && i <= end) {
				os << "line: " << i << " " << result.pData->at(i-1) << endl;
			}
		}
	}
}
#endif