#ifndef QUERYBASE_H
#define QUERYBASE_H

#include "TextQuery.h"

class QueryBase
{
	friend class Query;
protected:
	virtual ~QueryBase() = default;
private:
	// virtual const QueryResult eval(const TextQuery&) const = 0;
	virtual const string rep() const = 0;
};

#endif