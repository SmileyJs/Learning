#include <iostream>
#include <string>

using namespace std;

class Quote 
{
public:
	Quote() = default;
	Quote(const string &book, double sales_price)
		: bookNo(book), price(sales_price) { }

	string isbn() const { 
		return bookNo; 
	}

	virtual double net_price(size_t n) const {
		return n * price;
	}

	virtual void debug() const {
		cout << "data member: Quote" << "\n\tbookNo: " << bookNo << "\n\tprice: " << price << endl; 
	}

	virtual ~Quote() = default;

protected:
	double price = 0.0;

private:
	string bookNo;
};

double
print_total(ostream &os, const Quote &item, size_t n) 
{
	double price = item.net_price(n);

	os << "ISBN: " << item.isbn() << " #sold: " << n << "due: " << price << endl;

	return price;
}

class Bulk_Quote : public Quote 
{
public:
	Bulk_Quote() = default;
	Bulk_Quote(const string& book, double sales_price, size_t n, double discount)
		: Quote(book, sales_price), discount(discount), min_qty(n) { }

	virtual double net_price(size_t n ) const override {
		if (n < min_qty) {
			return n * price;
		}
		else {
			return n * price * (1 - discount);
		}
	}

	virtual void debug() const override {
		cout << "date member: Bulk_Quote" << "\n\tdiscount: " << discount << "\n\tmin_qty: " << min_qty << endl;
	}

private:
	double discount = 0.0;
	size_t min_qty = 0;
};

class Limit_Quote : public Quote
{
public:
	Limit_Quote() = default;
	Limit_Quote(const string& book, double sales_price, size_t n, double discount)
		: Quote(book, sales_price), discount(discount), max_qty(n) { }

	virtual double net_price(size_t n) const override {
		if (n >= max_qty) {
			return price * max_qty * (1 - discount) + price * (n - max_qty);
		}
		else {
			return price * n * (1 - discount);
		}
	}

	virtual void debug() const override {
		cout << "date member: Limit_Quote" << "\n\tdiscount: " << discount << "\n\tmax_qty: " << max_qty << endl;
	}

private:
	double discount = 0.0;
	int max_qty = 0;
};

int
main(int argc, char const *argv[])
{
	Quote a("aaa", 100);
	Bulk_Quote b("bbb", 100, 10, 0.2);
	Limit_Quote c("ccc", 100, 100, 0.2);

	print_total(cout, a, 70);
	print_total(cout, b, 70);
	print_total(cout, c, 70);

	return 0;
}