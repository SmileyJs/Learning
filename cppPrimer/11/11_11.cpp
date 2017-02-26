#include <iostream>
#include <set>

#include "../07/Sales_data.h"

using namespace std;

bool
compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

int
main(int argc, char const *argv[])
{
	multiset<Sales_data, decltype(compareIsbn) *> bookStore(compareIsbn);

	multiset<Sales_data, bool (*) (const Sales_data &, const Sales_data &)> bookStore2(compareIsbn);

	return 0;
}