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

	virtual const QueryResult eval(const TextQuery& t) const override;
	Query query;
};

inline Query
operator~(const Query& lhs) {
	cout << __PRETTY_FUNCTION__ << endl;
	return shared_ptr<QueryBase>(new NotQuery(lhs));
}

const QueryResult
NotQuery::eval(const TextQuery& t) const {
	cout << __PRETTY_FUNCTION__ << endl;
	QueryResult result = query.eval(t);

	auto ret = make_shared<set<unsigned>>();
	auto beg = result.begin(), end = result.end();

	for (auto i = 1; i <= result.getFile()->size(); ++i) {
		if (beg == end || *beg != i) {
			ret->insert(i);
		}
		else if (beg != end){
			++ beg;
		}
	}

	return QueryResult(rep(), ret, result.getFile());
}
#endif