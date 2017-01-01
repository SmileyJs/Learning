#include <iostream>
#include "Sales_data.h"

class NoDefault {
public:
	NoDefault(int x) : a(x) {};

private:
	int a;
};

class C {
public:
	C() : a(1) { }
private:
	NoDefault a;
};

int
main(int argc, char const *argv[])
{
	C c;

	// Sales_data data = "test explicit";
	Sales_data data2("test explicit");

	return 0;
}