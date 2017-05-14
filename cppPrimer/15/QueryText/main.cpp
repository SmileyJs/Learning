#include <fstream>

#include "TextQuery.h"
#include "QueryBase.h"
#include "Query.h"
#include "NotQuery.h"
#include "AndQuery.h"
#include "QueryHistory.h"

int
main(int argc, char const *argv[])
{
	ifstream input("./text.txt");

	if (!input) {
		cout << "file input error!" << endl;
		return -1;
	}

	TextQuery text(input);

  	Query q0 = Query("daddy"), q1 = Query("the"), q2 = Query("Daddy");

	QueryHistory history;
	history.addQuery(q0);
	history.addQuery(q1);
	history.addQuery(q2);

	Query q = history[0] & history[1] | ~history[2];

	cout << q << endl;

	print(cout, q.eval(text));
	print(cout, q.eval(text), 3, 7);

	return 0;
}