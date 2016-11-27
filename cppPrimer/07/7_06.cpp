#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int
main(int argc, char const *argv[])
{
	Sales_data total;
	if (read(cin, total)) {
		Sales_data trans;
		while (read(cin, trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(cout, total);
				cout << endl;
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