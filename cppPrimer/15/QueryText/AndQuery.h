#ifndef ANDQUERY_H
#define ANDQUERY_H

#include <algorithm>

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
	
	virtual const QueryResult eval(const TextQuery&) const override;
};

const QueryResult
AndQuery::eval(const TextQuery& text) const
{
	QueryResult left = lhs.eval(text);
	QueryResult right = rhs.eval(text);

	auto ret_lines = make_shared<set<unsigned>>();

	set_intersection(left.begin(), left.end(), right.begin(), right.end(),
		inserter(*ret_lines, ret_lines->begin()));

	return QueryResult(rep(), ret_lines, left.getFile());
}

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
private:
	OrQuery(const Query& l, const Query& r)
		: BinaryQuery(l, r, "|") 
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	virtual const QueryResult eval(const TextQuery&) const override;
};

const QueryResult
OrQuery::eval(const TextQuery& text) const
{
	QueryResult left = lhs.eval(text);
	QueryResult right = rhs.eval(text);

	auto ret_lines = make_shared<set<unsigned>>(left.begin(), left.end());

	ret_lines->insert(right.begin(), right.end());

	return QueryResult(rep(), ret_lines, left.getFile());
}

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