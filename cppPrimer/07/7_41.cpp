#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::cin;
using std::string;

// Delegating constructor
class Sales_data {

public:
	Sales_data(const string &s, unsigned n, double price)
		: bookNo(s), units_sold(n), revenue(price*n) {
			cout << "Delegating contructor" << endl;
		};

	Sales_data() : Sales_data("", 0, 0) {
		cout << "depend on Delegating constructor no parameter" << endl;
	};
	Sales_data(const string &s) : Sales_data(s, 0, 0) {
		cout << "depend on Delegating constructor only string parameter" << endl;
	};
	Sales_data(std::istream &is) : Sales_data() {
		cout << "depend on Delegating constructor only istream" << endl;
	};

private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};

int main(int argc, char const *argv[])
{
	Sales_data a("s", 1, 1);

	Sales_data b("s");

	Sales_data c;

	Sales_data d(cin);

	return 0;
}