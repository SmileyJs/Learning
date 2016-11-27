#include <iostream>

#include "Sales_data.h"

using std::cout;
using std::cin;
using std::endl;

int
main(int argc, char const *argv[])
{
	Sales_data total;

	if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				cout << total.isbn() << " " << total.units_sold << " " << total.revenue << endl;
				total = trans;
			}
		}
	}
	else {
		std::cerr << "No data?" << endl;
		return -1;
	}

	return 0;
}