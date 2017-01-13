#include <iostream>
#include <fstream>

using namespace std;

class Sales_data {
	friend istream& read(istream &, Sales_data &);
	friend ostream& print(ostream &, const Sales_data &);

public:
	Sales_data() = default;
	Sales_data(const string &str) : bookNo(str) { };
	Sales_data(const string &str, unsigned units, double price) : 
		bookNo(str), units_sold(units), revenue(units_sold*price) { };

	Sales_data& combine(const Sales_data &);
	string isbn() const {return bookNo;};

private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

istream&
read(istream &is, Sales_data &item) {
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is; 
}

ostream&
print(ostream &os, const Sales_data &item) {
	os << item.bookNo << " " << item.units_sold << item.revenue;
	return os;
}

Sales_data&
Sales_data::combine(const Sales_data &item) {
	units_sold += item.units_sold;
	revenue += item.revenue;

	return *this;
}

int
main(int argc, char const *argv[])
{
	string fileName = argv[1];
	ifstream ifs(fileName);
	Sales_data total;
	if (read(ifs, total)) {
		Sales_data trans;
		while (read(ifs, trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(cout , total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else {
		cout << "No data?" << endl;
	}


	return 0;
}