#include <iostream>

using namespace std;

int main()
{
#if 0
	int i = 0, &r = i;
	auto a = r;

	const int ci = i, &cr = ci;

	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;

	const auto f = ci;

	auto &g = ci;
//	auto &h = 42;
	const auto &j = 42;

	auto k = ci, &l = i;
	auto &m = ci, *p = &ci;
//	auto &n = i, *p2 = &ci;

// The following code is for 2.33
	a = 42;
	b = 42;
	c = 42;
//	d = 42;
//	e = 42;
//	g = 42;
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
//	cout << "d = " << d << endl;
//	cout << "e = " << e << endl;
//	cout << "g = " << g << endl;	

#endif
	const int i = 42;
	auto j = i;
	const auto &k = i;
	auto *p = &i;
	const auto j2 = i, &k2 = i;	
	
	return 0;
}

