#include "chapter6.h"

int 
main(int argc, char const *argv[])
{
	vector<int (*)(const int &, const int &)> vec = 
		{add, dec, multi, div};
	
	// for (auto i : vec) {
	// 	cout << i(4, 2) << endl;
	// }

	for (vector<int (*)(const int &, const int &)>::iterator i = vec.begin();
			 i != vec.end(); ++i) {
		cout << (*i)(4, 2) << endl;
	}

	return 0;
}

int
add (const int &a, const int &b)
{
	return a + b;
}

int
dec(const int &a, const int &b)
{
	if (a > b) {
		return a - b;
	}
	else {
		return b - a;
	}
}

int
multi(const int &a, const int &b)
{
	return a * b;
}

int
div(const int &a, const int &b)
{
	return a / b;
}