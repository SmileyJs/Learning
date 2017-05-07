#include "TextQuery.h"
#include "Query.h"
#include "QueryBase.h"
#include "NotQuery.h"
#include "AndQuery.h"

int
main(int argc, char const *argv[])
{
	Query q = Query("s") | Query("a");

	return 0;
}