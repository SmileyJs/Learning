#include <iostream>

using namespace std;

class funcObj
{
public:
	// funcObj();
	// ~funcObj();
	
	const string& operator()(bool, const string&, const string&);
};

const string&
funcObj::operator()(bool flag, const string& s1, const string& s2)
{
	return flag ? s1 : s2;
}

int
main(int argc, char const *argv[])
{
	funcObj a;
	cout << a(1, "true", "false") << endl;

	return 0;
}