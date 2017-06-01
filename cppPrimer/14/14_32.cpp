#include <iostream>
#include "../12/StrBlob.h"

using namespace std;

class Test_StrPtr{
public:
	Test_StrPtr() = default;
	Test_StrPtr(StrBlobPtr *p) : m_ptr(p)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	
	StrBlobPtr& operator*() {
		cout << __PRETTY_FUNCTION__ << endl;
		return *m_ptr;
	}

	StrBlobPtr* operator->() {
		cout << __PRETTY_FUNCTION__ << endl;
		return & this->operator*();
	}

private:
	StrBlobPtr* m_ptr;
};

int
main(int argc, char const *argv[])
{
	StrBlob str{"aaa", "bbb"};

	StrBlobPtr iter = str.begin();

	Test_StrPtr a(&iter);

	cout << a->deref() << endl;

	return 0;
}