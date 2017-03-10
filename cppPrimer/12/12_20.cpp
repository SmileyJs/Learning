#include "StrBlob.h"

int
main(int argc, char const *argv[])
{
	StrBlob con;
	string text;

	while (getline(cin, text)) {
		con.push_back(text);
	}

	for (StrBlobPtr pBegin(con.begin()), pEnd(con.end()); pBegin != 
		pEnd; pBegin.incr()) {
		cout << pBegin.deRef() << endl;
	}

	return 0;
}