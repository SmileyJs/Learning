#ifndef NOTQUERY_H
#define NOTQUERY_H

#include "QueryBase.h"
#include "Query.h"

class NotQuery : public QueryBase
{
	friend Query operator~(const Query&);
private:
	NotQuery(const Query& lhs) 
		: query(lhs)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}

	virtual const string rep() const override {
		cout << __PRETTY_FUNCTION__ << endl;
		return "~(" + query.rep() +  ")"; 
	}

	// virtual const QueryResult eval(const TextQuery& t) const override;
	Query query;
};

inline Query
operator~(const Query& lhs) {
	cout << __PRETTY_FUNCTION__ << endl;
	return shared_ptr<QueryBase>(new NotQuery(lhs));
}

#endif