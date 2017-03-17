#include "../12/StrBlob.h"

int
main(int argc, char const *argv[])
{
	StrBlob str({"123", "234"});
	cout << "StrBlob before: " << str.count() << endl;
	StrBlob str_cp(str);
	cout << "StrBlob after: " << str_cp.count() << endl;

	StrBlobPtr strPtr(str);
	cout << "StrBlobPtr before: " << strPtr.count() << endl;
	StrBlobPtr strPtr_cp(strPtr);
	cout << "StrBlobPtr after: " << strPtr_cp.count() << endl;

	return 0;
}