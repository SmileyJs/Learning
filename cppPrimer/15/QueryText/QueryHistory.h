#ifndef QUERYHISTORY_H
#define QUERYHISTORY_H
#include "Query.h"
#endif

class QueryHistory
{
public:
	Query& operator[](size_t n) const {
		return *(queryVec[n]);
	}

	void addQuery(const Query& lhs) {
		shared_ptr<Query> p = make_shared<Query>(lhs);
		queryVec.push_back(p);
	}

private:
	vector<shared_ptr<Query>> queryVec;	
};