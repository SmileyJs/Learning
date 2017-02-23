#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <iterator>
#include "../07/Sales_data.h"

using namespace std;

bool
compareIsbn(const Sales_data &d1, const Sales_data &d2)
{
	return d1.isbn() < d2.isbn();
}

int
main(int argc, char const *argv[])
{
	vector<Sales_data> vec{Sales_data("111", 2, 3), Sales_data("222", 2, 4),
		Sales_data("111", 1, 3), Sales_data("222", 1, 4), Sales_data("333", 4, 1)};

	sort(vec.begin(), vec.end(), compareIsbn);

	for (auto i = vec.begin(), j = vec.end(); i != vec.end(); i = j) {
		j = find_if(i, vec.end(), [i](const Sales_data &d)->bool {
			return d.isbn() != i->isbn();
		});

		print(cout, accumulate(i, j, Sales_data(i->isbn())));
		cout << endl;
	}

	return 0;
}