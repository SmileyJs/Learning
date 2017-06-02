#include <iostream>

using namespace std;

struct SmallInt
{
	friend SmallInt operator+(const SmallInt&, const SmallInt&);
	SmallInt(int i = 0) : value(i) {
		cout << __PRETTY_FUNCTION__ << endl;
	}

	operator int() const {
		cout << __PRETTY_FUNCTION__ << endl;
		return value;
	}

	int value;
};

SmallInt
operator+(const SmallInt&, const SmallInt&)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return SmallInt();
}

struct LoneDouble
{
	LoneDouble(double i = 0.0) : value(i) {
		cout << __PRETTY_FUNCTION__ << endl;
	}

	operator double() const {
		cout << __PRETTY_FUNCTION__ << endl;
		return value;
	}

	LoneDouble operator+(const SmallInt&) {
		cout << __PRETTY_FUNCTION__ << endl;
		return LoneDouble();
	}

	double value;
};

LoneDouble
operator+(LoneDouble&, double)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return LoneDouble();
}

int
main(int argc, char const *argv[])
{
	SmallInt si;
	LoneDouble ld;

	ld = ld + si;
	cout << "====" << endl;
	ld = si + ld;

	double d = int(si) + 3.14;

	return 0;
}