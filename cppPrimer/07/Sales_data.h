
using std::string;
using std::istream;
using srd::ostream;

struct Sales_data{
	string isbn() const { return bookNo;};
	Sales_data& conbine(const Sales_data &rhs);

	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data&
Sales_data::conbine(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;

	return *this;
}

istream&
read(istream &is, Sales_data &item) {
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;

	return is;
}

ostream&
print(ostream &os, Sales_data &item) {
	

	return os;
}