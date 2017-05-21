
#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;

class Sales_data;
istream &read(istream &, Sales_data&);

class Sales_data{
	friend istream &read(istream &, Sales_data &item);
	friend ostream &print(ostream &, const Sales_data &);
	friend Sales_data add(Sales_data &, Sales_data &);

	friend ostream& operator<<(ostream &os, const Sales_data &c);
	friend istream& operator>>(istream &is, Sales_data &c);

public:
	Sales_data() = default;
	Sales_data(istream &is) {
		read(is, *this);
	};
	Sales_data(const string &s) : bookNo(s) { };
	Sales_data(const string &s, unsigned n, double price) : 
		bookNo(s), units_sold(n), revenue(price*n) { };

	Sales_data& operator+=(const Sales_data &);
	Sales_data& operator=(const string&);

	// 7_14
	// Sales_data() : units_sold(0), revennu(0.0) { };

	string isbn() const { return bookNo;};
	double avg_price() const;
	Sales_data& combine(const Sales_data &rhs);

private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


Sales_data
&Sales_data::combine(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;

	return *this;
}

inline double 
Sales_data::avg_price() const {
	if (units_sold) {
		return revenue/units_sold;
	}
	else {
		return 0;
	}
}

istream
&read(istream &is, Sales_data &item) {
	double price;
	is >> item.bookNo >> item.units_sold >> price; 
	item.revenue = price * item.units_sold; // item can't be const, if it is const object, >> change bookNo's value is legal??
	return is;
}

ostream
&print(ostream &os, const Sales_data &item) {
	os << item.bookNo << " " << item.units_sold << " " << item.revenue 
		<< " " << item.avg_price();
	return os;
}

Sales_data
add(Sales_data &lhs, Sales_data&rhs) {
	Sales_data sum;
	sum = lhs;
	sum.combine(rhs);
	return sum;
}

// Sales_data&
// Sales_data::operator+=(const Sales_data &rhs)
// {
// 	Sales_data old = *this;
// 	*this = old + rhs;

// 	return *this;
// }

// Sales_data
// operator+(const Sales_data &lhs, const Sales_data &rhs)
// {
// 	Sales_data ret;
// 	ret.units_sold = lhs.units_sold + rhs.units_sold;
// 	ret.revenue = lhs.revenue + rhs.revenue;

// 	return ret;
// }

Sales_data&
Sales_data::operator+=(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;

	return *this;
}

Sales_data
operator+(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data ret(lhs);
	ret += rhs;

	return ret;
}

// Sales_data::Sales_data(istream &is) {
// 	read(is, *this);
// }

ostream&
operator<<(ostream &os, const Sales_data &c)
{
	os << c.bookNo << " " << c.units_sold << " " << c.revenue 
		<< " " << c.avg_price();

	return os;
}

istream&
operator>>(istream &is, Sales_data &c)
{
	double price = 0.0;
	is >> c.bookNo >> c.units_sold >> price;

	if (is) {
		c.revenue = price * c.units_sold;
	}
	else {
		c = Sales_data();
	}

	return is;
}

Sales_data&
Sales_data::operator=(const string& isbn)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	*this = Sales_data(isbn);

	return *this;
}