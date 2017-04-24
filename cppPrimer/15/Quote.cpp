#include <iostream>
#include <string>

using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(const string& bookNo, double price) 
		: bookNo(bookNo), price(price) {}

	virtual ~Quote() = default;
	
	const string isbn() const {
		return bookNo;
	}

	virtual double net_price(size_t n) const {
		return n * price;
	}

	virtual void debug() const {
		cout << "data member: Quote\n" << "\tbookNo: " << bookNo << "\n\tprice: " << price << endl;
	}

private:
	string bookNo;
protected:
	double price = 0.0;		
};

double
print_total(ostream& os, const Quote& item, size_t n)
{
	double ret = item.net_price(n);
	os << "bookNo: " << item.isbn() << "\tsold: " << n << "\ttotal_due: " << ret << endl;

	return ret;
}

class Disc_Quote : public Quote
{
public:
	Disc_Quote() = default;
	Disc_Quote(const string& bookNo, double price, size_t n, double disc)
		: Quote(bookNo, price), quantity(n), discount(disc) {}

	virtual ~Disc_Quote() = default;

	virtual double net_price(size_t n) const = 0;

protected:
	size_t quantity  = 0;
	double discount = 0.0;
};

class Bulk_Quote : public Disc_Quote
{
public:
	Bulk_Quote() = default;
	Bulk_Quote(const string& bookNo, double price, size_t n, double disc)
		: Disc_Quote(bookNo, price, n, disc) {}

	virtual ~Bulk_Quote() = default;

	virtual double net_price(size_t n) const override {
		if (n < quantity) {
			return n * price;
		}
		else {
			return n * price * (1 - discount);
		}
	}

	virtual void debug() const {
		cout << "data member: Bulk_Quote\n" << "\tquantity: " << quantity << "\n\tdiscount: " << discount << endl;
	}
};

class Limit_Quote : public Disc_Quote
{
public:
	Limit_Quote() = default;
	Limit_Quote(const string& bookNo, double price, size_t n, double disc)
		: Disc_Quote(bookNo, price, n, disc) {}

	virtual ~Limit_Quote() = default;
	
	virtual double net_price(size_t n) const override {
		if (n < quantity) {
			return n * price;
		}
		else {
			return quantity * price + (1 - discount) * (n - quantity) * price;
		}
	}

	virtual void debug() const {
		cout << "data member: Limit_Quote\n" << "\tquantity: " << quantity << "\n\tdiscount: " << discount << endl;
	}
};

int
main(int argc, char const *argv[])
{
	Quote a("aaa", 100);
	Bulk_Quote b("bbb", 100, 50, 0.2);
	Limit_Quote c("ccc", 100, 50, 0.2);

	print_total(cout, a, 70);
	print_total(cout, b, 70);
	print_total(cout, c, 70);

	// Disc_Quote d("ddd", 100, 50, 0.2);

	return 0;
}
