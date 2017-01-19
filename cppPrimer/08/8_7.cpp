#include <iostream>
#include <fstream>

using namespace std;

class Sales_data {
	friend istream& read(istream &, Sales_data &);
	friend ostream& print(ostream &, const Sales_data &);
public:
	Sales_data() = default;
	Sales_data(string s, unsigned n, double price)
		: bookNo(s), units_sold(n), revenue(price*n) { };
	Sales_data(string s) : bookNo(s) { };

	Sales_data& combine(const Sales_data &);
	string isbn() {return bookNo;};

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
	os << item.bookNo << " " << item.units_sold << " " << item.revenue;
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
	if (argc != 3) {
		cout << "argument error, please try again!" << endl;
		return -1;
	}

	ifstream ifs(argv[1]);
	ofstream ofs(argv[2], ostream::app);

	if (ifs) {
		Sales_data total;
		if (read(ifs, total)) {
			Sales_data trans;
			while (read(ifs, trans)) {
				if (trans.isbn() == total.isbn()) {
					total.combine(trans);
				}
				else {
					print(ofs, total) << endl;
					total = trans;
				}
			}
			print(ofs, total) << endl;
		}
		else {
			cout << "No data?" << endl;
		}
	}

	return 0;
}