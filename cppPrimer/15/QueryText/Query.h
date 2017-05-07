#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <fstream>

#include "QueryBase.h"
#include "WordQuery.h"

class Query
{
	friend Query operator~(const Query&);
	friend Query operator&(const Query&, const Query&);
	friend Query operator|(const Query&, const Query&);
public:
	// const QueryResult eval(const TextQuery& t) const 
	// { 
	// 	return item->eval(t);
	// }
	const string rep() const
	{
		return item->rep();
	}
	Query(const string &s) : item(new WordQuery(s)) { cout << __PRETTY_FUNCTION__ << endl; }

private:
	Query(shared_ptr<QueryBase> query) : item(query) { cout << __PRETTY_FUNCTION__ << endl; }
	shared_ptr<QueryBase> item;
};

ostream&
operator<<(ostream& os, const Query& q)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return os << q.rep();
}

#endif