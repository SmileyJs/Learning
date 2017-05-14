#ifndef WORDQUERY_H
#define WORDQUERY_H

#include "QueryBase.h"

class WordQuery : public QueryBase
{
private:
	friend class Query;
	WordQuery(const string& s) :query_word(s) 
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}

	virtual const QueryResult eval(const TextQuery& t) const override 
	{
		return t.query(query_word);
	};

	virtual const string rep() const override 
	{ 
		cout << __PRETTY_FUNCTION__ << endl;
		return query_word; 
	}

	string query_word;
};

#endif