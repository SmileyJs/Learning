#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

class Foo {
public:
	Foo(const Foo&);
	Foo(initializer_list<int> il);

	Foo sorted() const &;
	Foo sorted() &&;
private:
	vector<int> data;
};

Foo::Foo(const Foo &c)
{
	cout << "Foo::Foo(const Foo &c)" << endl;

	copy(c.data.begin(), c.data.end(), back_inserter(data));
}

Foo::Foo(initializer_list<int> il)
{
	cout << "Foo::Foo(initializer_list<int> il)" << endl;

	copy(il.begin(), il.end(), back_inserter(data));
}

Foo
Foo::sorted() const &
{
	cout << "Foo::sorted() const &" << endl;

	Foo ret(*this);
	sort(ret.data.begin(), ret.data.end());
	return ret;
}

Foo
Foo::sorted() &&
{
	cout << "Foo::sorted() &&" << endl;

	sort(data.begin(), data.end());
	return *this;
}