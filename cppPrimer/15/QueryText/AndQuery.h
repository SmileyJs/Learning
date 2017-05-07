#ifndef ANDQUERY_H
#define ANDQUERY_H

#include "BinaryQuery.h"
#include "Query.h"

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
private:
	AndQuery(const Query& l, const Query& r)
		: BinaryQuery(l, r, "&") 
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	
	// virtual const QueryResult eval(cosnt TextQuery&) const override;
};

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
private:
	OrQuery(const Query& l, const Query& r)
		: BinaryQuery(l, r, "|") 
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	// virtual const QueryResult eval(const TextQuery&) override;
};

inline Query
operator&(const Query& lhs, const Query& rhs)
{
	return shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

inline Query
operator|(const Query &lhs, const Query& rhs)
{
	return shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

#endif