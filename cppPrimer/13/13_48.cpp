#include "String.h"
#include <vector>

int
main(int argc, char const *argv[])
{
	// vector<String> v = {"11", "22"};

	// v.push_back("a")
	// v.push_back("b")
	// v.push_back("c")
	// v.push_back("d")
	// v.push_back("e")
	// v.push_back("f")
	// v.push_back("g")
	// v.push_back("h")
	// v.push_back("i")
	// v.push_back("j")

	String a("aa");
	String b(a);
	b = a;
	String c = a, d = a, e = a, f = a, g = a, h = a, i = a;

	vector<String> v;


	cout << "test push_back a" << endl;
	// v.reserve(8); 

	// if class String has no move_constructor,
	// every time v to increment its' size, all elements in it will be re construct(copy).
	// if class String has move_constructor, it will use move_constructor instread of 
	// copy_constructor except the new one you pushed. 
	v.push_back(a);
	cout << "test push_back b" << endl;
	v.push_back(b);
	cout << "test push_back c" << endl;
	v.push_back(c);
	cout << "test push_back d" << endl;
	v.push_back(d);
	cout << "test push_back e" << endl;
	v.push_back(e);
	// cout << a << endl;

	// 13_50
	cout << "test_13_52" << endl;
	String aa("hahaha");
	String bb(std::move(aa));

	string cc("XXXXXX");
	cout << "before move " << cc << endl;

	string dd(std::move(cc));
	cout << "after move cc = " << cc << " dd = " << dd << endl;

	return 0;
}