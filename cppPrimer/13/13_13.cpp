#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct X {
	X() { cout << "X()" << endl; }
	X(const X &cp) { cout << "X{const X &}" << endl; }
	~X() { cout << "~X()" << endl; }
	X& operator=(const X &cp) { 
		cout << "operator=(const X)" << endl; 
		return *this;
	}
private:
	string s = "";
};

void testA(X &a)
{
	cout << "test A" << endl;
	vector<X> vec;
	vec.push_back(a);
}

void testB(X a) 
{
	cout << "test B" << endl;
	vector<X> vec;
	vec.push_back(a);
}

int
main(int argc, char const *argv[])
{
	X a, b = a;
	X *c = new X();

	*c = a;

	cout << "call test A start" << endl;
	testA(a);
	cout << "call test A end" << endl;

	cout << "call test B start" << endl;
	testB(a);
	cout << "call test B end" << endl;

	delete c;

	return 0;
}
