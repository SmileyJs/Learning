#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include "QueryBase.h"
#include "Query.h"

class BinaryQuery : public QueryBase
{
protected:
	BinaryQuery(const Query& lhs, const Query& rhs, string& s)
		: lhs(lhs), rhs(rhs), opSym(s) {}
	
	virtual const string rep() const override {
		return lhs.rep() + " " + opSym + " " + rhs.rep();
	}

	// derive pure virtual eval, so Binary is also a abstract class.

	Query lhs, rhs;
	string opSym;
};

#endif