#include <iostream>
#include <vector>	

using namespace std;

template <typename T>
void g(T&& val){
	cout << __PRETTY_FUNCTION__ << endl;
}

	template <typename T>
	void f(T) {
		cout << __PRETTY_FUNCTION__ << endl;
	}

template <typename T>
void e(const T&) {
	cout << __PRETTY_FUNCTION__ << endl;
}

template <typename T>
void d(T&& val) {
	cout << __PRETTY_FUNCTION__ << endl;
	vector<T> v;
}

int
main(int argc, char const *argv[])
{
	int i = 0;
	const int ci = i;

	g(i);
	g(ci);
	g(i*ci);
	g(i = ci);

	f(i);
	f(ci);
	f(i*ci);
	f(i=ci);

	e(i);
	e(ci);
	e(i*ci);
	e(i=ci);

	d(42);
	d(i);	

	return 0;
}	