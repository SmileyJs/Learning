#include <iostream>
#include <algorithm>
#include <unordered_set>

#include "../07/Sales_data.h"

using namespace std;


namespace std {

template <>
struct hash<Sales_data> {
	typedef size_t result_type;
	typedef Sales_data argument_type;
	size_t operator() (const Sales_data& s) const;
};

size_t hash<Sales_data>::operator()(const Sales_data& s) const
{
	return hash<string>()(s.bookNo) ^
		hash<unsigned>()(s.units_sold) ^
		hash<double>()(s.revenue);
}

}

int
main(int argc, char const *argv[])
{
	unordered_set<Sales_data> set = {{"111", 111, 1.1}, {"222", 222, 2.2}, {"333", 333, 3.3}};

	for (auto i : set) {
		cout << i << endl;
	}

	return 0;
}