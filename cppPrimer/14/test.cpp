#include "../13/String.h"
#include "../12/StrBlob.h"
#include "../13/StrVec.h"

int
main(int argc, char const *argv[])
{
	String a("111");
	const String b("222");

	if (a == b) {
		cout << "String ==" << endl;
	}
	else {
		cout << "String !=" << endl;
	}

	if (a <= b) {
		cout << "String <=" << endl;
	}
	else {
		cout << "String >" << endl;
	}

	a[1] = '2';
	// b[0] = '1'; compile error.
	cout << a << endl;

	StrBlob c{"bb", "bb"};
	const StrBlob d{"aa", "cc"};

	if (c == d) {
		cout << "strBlob ==" << endl;
	}
	else {
		cout << "strBlob !=" << endl;
	}

	if (c < d) {
		cout << "StrBlob <" << endl;
	}
	else {
		cout << "StrBlob >=" << endl;
	}

	c[0] = "dd";
	// d[1] = "ee"; compile error.

	StrVec e{"aaa", "bbb"};
	const StrVec f{"bbb", "bbb"};

	if (e == f) {
		cout << "StrVec ==" << endl;
	}
	else {
		cout << "StrVec !=" << endl;
	}

	if (e <= f) {
		cout << "StrVec <=" << endl;
	}
	else {
		cout << "StrVec >" << endl;
	}

	e[1] = "js";
	// f[0] = "js"; compile error.

	return 0;
}