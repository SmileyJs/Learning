#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int
main(int argc, char *argv[])
{
	// 4-36
	int i = 2;
	double d = 3.14;

	i *= static_cast<int>(d);

	cout << i << endl;

	// 4-37
	const string *ps;
	char *pc;
	void *pv;

	pv = static_cast<void *>(const_cast<string *>(ps));
	i = static_cast<int>(*pc);
	pv = static_cast<double *>(&d);
	pc = static_cast<char *>(pv);

	return 0;
}