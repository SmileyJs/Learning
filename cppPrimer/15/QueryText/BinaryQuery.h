#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include "QueryBase.h"
#include "Query.h"

class BinaryQuery : public QueryBase
{
protected:
	BinaryQuery(const Query& l, const Query& r, const string& s)
		: lhs(l), rhs(r), opSym(s) {}
	
	virtual const string rep() const override {
		cout << __PRETTY_FUNCTION__ << " " + opSym << endl;
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}

	// derive pure virtual eval, so Binary is also a abstract class.

	Query lhs, rhs;
	string opSym;
};

#endif