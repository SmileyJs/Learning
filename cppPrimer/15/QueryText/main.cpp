#include "TextQuery.h"
#include "QueryBase.h"
#include "Query.h"
#include "NotQuery.h"
#include "AndQuery.h"

int
main(int argc, char const *argv[])
{
	Query q = Query("s") & Query("a") | Query("b");

	cout << q << endl;;

	return 0;
}