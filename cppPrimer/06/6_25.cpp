#include "chapter6.h"

int
main(int argc, char const *argv[])
{
	cout << argv[1] << argv[2] << endl;

	string str;

	for (int i = 1; i != argc; ++i) {
		str += argv[i];
	}

	cout << str << endl;

	return 0;
}