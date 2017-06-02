#include <iostream>

using namespace std;

class base_class
{
public:
	// base_class() {};
	// virtual ~base_class() {};

protected:
	virtual void f1() {
		cout << __PRETTY_FUNCTION__ << endl;
	}

	virtual void f2() {
		cout << __PRETTY_FUNCTION__ << endl;
	}

	virtual void f3() {
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

class drived1 : public base_class
{
public:
	drived1();
	virtual ~drived1();

protected:
	virtual void f1() override {
		cout << __PRETTY_FUNCTION__ << endl;
	}

	virtual void f2() override {
		cout << __PRETTY_FUNCTION__ << endl;
	}

	virtual void f3() override {
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

int
main(int argc, char const *argv[])
{
	base_class bc;

	cout << &bc << endl;
	cout << (void*)&bc << endl;
	cout << (long*)*(long*)&bc + 0 << endl;
	cout << (long*)*(long*)&bc + 1 << endl;
	cout << (long*)*(long*)&bc + 2 << endl;
	cout << *((int*)*(long*)&bc + 3) << endl;

	typedef void(*funcPointer)(void);
	funcPointer fp = NULL;

	fp = (funcPointer)*((long*)*(long*)&bc + 0);
	fp();
	fp = (funcPointer)*((long*)*(long*)&bc + 1);
	fp();
	fp = (funcPointer)*((long*)*(long*)&bc + 2);
	fp();

	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;

	// typedef void(*func)(void);

	// auto ptr = (long*)*(long*)&bc;

	// func pf = NULL;

	// pf = (func)ptr[0];

	// pf();

	return 0;
}