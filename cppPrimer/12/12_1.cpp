#include "StrBlob.h"

int
main(int argc, char const *argv[])
{
	// comments is illegal while constructor declared as explicit 
	StrBlob b1/* = {"1", "2", "3"}*/;

	// vector<string> v{"1", "2", "3", "4"};
	StrBlob b2({"1", "2", "3", "4"});

	while (!b1.empty()) {
		cout << b1.back() << endl;
		b1.pop_back();
	}

	cout << "================" << endl;

	while (!b2.empty()) {
		cout << b2.back() << endl;
		b2.pop_back();
	}

	return 0;
}