#include <iostream>
#include <numeric>
#include <algorithm>

#include "../07/Sales_data.h"

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	std::cout << lhs.isbn() << "  " << rhs.isbn() << std::endl;
	// return lhs.isbn() < rhs.isbn();
	return lhs.isbn().size() < rhs.isbn().size();
}

int
main(int argc, char const *argv[])
{
	// std::vector<Sales_data> vec;

	// for (int i = 9; i > 0; --i) {
	// 	vec.emplace_back(std::to_string(i));
	// }

	Sales_data d1("aaa"), d2("bbb"), d3("aaz"), d4("bba"), d5("aaaa"), d6("bz");

	std::vector<Sales_data> vec{d1, d2, d3, d4, d5, d6};

	for (auto i : vec) {
		print(std::cout, i);
		std::cout << std::endl;
	}

	sort(vec.begin(), vec.end(), compareIsbn);

	for (auto i : vec) {
		print(std::cout, i);
		std::cout << std::endl;
	}

	return 0;
}

