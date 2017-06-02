#include <iostream>

#include "../07/Sales_data.h"

using namespace std;

int
main(int argc, char const *argv[])
{
	Sales_data test("aaa", 5, 10.1);

	cout << static_cast<string>(test) << endl;
	cout << static_cast<double>(test) << endl;

	return 0;
}