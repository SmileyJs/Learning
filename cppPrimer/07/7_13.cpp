#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int
main(int argc, char const *argv[])
{
	Sales_data total(cin);
	if (!total.isbn().empty()) {
		while (cin) {
			Sales_data trans(cin);
			if (trans.isbn() == total.isbn()) {
				add(total, trans);
			}
			else {
				print(cout, total) << endl;
				total = trans;
			}
		}
	}
	else {
		cerr << "No data?" << endl;
		return -1;
	}

	return 0;
}