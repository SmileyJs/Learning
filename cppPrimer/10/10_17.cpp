#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

#include "../07/Sales_data.h"

void print(const std::vector<Sales_data> &vec)
{
	for (auto i : vec) {
		std::cout << i.isbn() << std::endl;
	}
}

int
main(int argc, char const *argv[])
{
	Sales_data d1("aaa"), d2("bbb"), d3("aaz"), d4("bba"), d5("aaaa"), d6("bz");

	std::vector<Sales_data> vec{d1, d2, d3, d4, d5, d6};

	print(vec);

	sort(vec.begin(), vec.end(), [] (const Sales_data &s1, const Sales_data &s2) -> bool 
		{ return s1.isbn() < s2.isbn(); });

	print(vec);

	return 0;
}