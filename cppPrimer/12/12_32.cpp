#include "StrBlob.h"
#include <map>
#include <set>
#include <sstream>
#include <fstream>

class QueryResult;

class TextQuery {
public:
	using LineNo = vector<string>::size_type;

	TextQuery(ifstream &);

	QueryResult query(const string &);

private:
	shared_ptr<StrBlob> file;
	map<string, shared_ptr<set<LineNo>>> wordMap; 
};

TextQuery::TextQuery(ifstream &input)
	: file(new StrBlob())
{
	string line;

	while (getline(input, line)) {
		file->push_back(line);
		LineNo n = file->size();

		string word;
		istringstream lineStream(line);
		while (lineStream >> word) {
			auto &res = wordMap[word];
			if (!res) {
				res.reset(new set<LineNo>());
			}
			res->insert(n);
		}
	} 
}

class QueryResult {
public:
	friend void print(ofstream &, QueryResult);

	QueryResult(const string &s, shared_ptr<set<TextQuery::LineNo>> linePtr, shared_ptr<StrBlob> data)
		: word(s), pLines(linePtr), pData(data) {}

	// 12_33
	shared_ptr<StrBlob> get_file() const;
	set<TextQuery::LineNo>::iterator begin() const;
	set<TextQuery::LineNo>::iterator end() const;

private:
	string word;
	shared_ptr<set<TextQuery::LineNo>> pLines;
	shared_ptr<StrBlob> pData;
};

shared_ptr<StrBlob>
QueryResult::get_file() const
{
	return pData;
}

set<TextQuery::LineNo>::iterator 
QueryResult::begin() const
{
	return pLines->begin();
}

set<TextQuery::LineNo>::iterator
QueryResult::end() const
{
	return pLines->end();
}

QueryResult
TextQuery::query(const string &s)
{
	auto found = wordMap.find(s);

	static shared_ptr<set<TextQuery::LineNo>> noData(new set<TextQuery::LineNo>());

	if (found == wordMap.end()) {
		return QueryResult(s, noData, file);
	}
	else {
		return QueryResult(s, found->second, file);
	}
}

void
print(ofstream &output, QueryResult result)
{
	output << "element " << result.word << " occurs " << result.pLines->size() 
		<< ((result.pLines->size() > 1) ? " times." : " time.") << endl;

	// for (auto i : *result.pLines) {
	// 	ConstStrBlobPtr p(*result.pData, i - 1);

	// 	output << "\t(line " << i << " ) " << p.deRef() << endl;
	// }

	for (auto i = result.begin(); i != result.end(); ++i) {
		ConstStrBlobPtr p(*result.pData, *i - 1);
		output << "\t(line " << *i << " ) " << p.deRef() << endl;
	}
}

void
runQuery(ifstream &input, ofstream &output)
{
	TextQuery tq(input);

	do {
		cout << "please enter word to search or enter q to quit: " << endl;
		string word;
		if (!(cin >> word) || word == "q") break;
		print(output, tq.query(word));
	}
	while (true);
}

int
main(int argc, char const *argv[])
{
	ifstream input("BookList.txt");
	ofstream output("output.txt");

	if (!input) {
		cout << "input file error!" << endl;
		return -1;
	}

	if (!output) {
		cout << "output file error!" << endl;
		return -1;
	}

	runQuery(input, output);

	return 0;
}