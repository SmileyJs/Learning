#include "Sales_data.h"

using std::cout;
using std::cin;
using std::endl;

int
main(int argc, char const *argv[])
{
	Sales_data t1;
	print(cout, t1) << endl;
	Sales_data t2(cin);
	print(cout, t2) << endl;
	Sales_data t3("t3");
	print(cout, t3) << endl;
	Sales_data t4("t4", 10, 1.1);
	print(cout, t4) << endl;

	return 0;
}