#include <iostream>
#include <map>
#include <set>
#include "../07/Sales_data.h"

using namespace std;

bool
compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() > rhs.isbn();
}

int
main(int argc, char const *argv[])
{
	using compareType = bool (*)(const Sales_data &lhs, const Sales_data &rhs);

	multiset<Sales_data, compareType> bookStore(compareIsbn);
	multiset<Sales_data, bool (*) (const Sales_data &, const Sales_data &)> bookStore2(compareIsbn);

	multiset<Sales_data, bool (*) (const Sales_data &, const Sales_data &)>::const_iterator iter = bookStore.begin();

	return 0;
}