#include <iostream>
#include <set>

#include "15_26.cpp"

using namespace std;

class Basket
{
public:
	void addItem(const Quote& sale) {
		item.insert(shared_ptr<Quote>(sale.clone()));
	}

	void addItem(Quote&& sale) {
		item.insert(shared_ptr<Quote>(std::move(sale).clone()));
	}

	double total_receipt(ostream& os) const;

private:
	static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	multiset<shared_ptr<Quote>, decltype(compare) *> item{compare};		
};

double
Basket::total_receipt(ostream& os) const{
	double sum = 0.0;
	for (auto i = item.cbegin(); i != item.cend(); i = item.upper_bound(*i)) {
		sum += print_total(os, **i, item.count(*i));
	}

	os << "Total sales: " << sum << endl;
	return sum;
}


int
main(int argc, char const *argv[])
{
	Quote a("aaa", 10);
	Bulk_Quote b("bbb", 10, 0.2, 50);

	// Quote a1 = a;
	// Bulk_Quote b1 = b;

	// Quote a2 = Quote("ccc", 10);
	// Bulk_Quote b2 = Bulk_Quote("ddd", 10, 0.2, 50);

	// Quote a2;
	// a2 = a1;
	// Bulk_Quote b2;
	// b2 = b1;

	// 15_28
	vector<Quote> iVec;
	iVec.push_back(a);
	iVec.push_back(b);

	for (auto i = iVec.cbegin(); i != iVec.cend(); ++i) {
		cout << i->net_price(70) << endl;
	}	

	vector<shared_ptr<Quote>> pVec;

	shared_ptr<Quote> p1 = make_shared<Quote>(a);
	shared_ptr<Bulk_Quote> p2 = make_shared<Bulk_Quote>(b);

	pVec.push_back(p1);
	pVec.push_back(p2);

	for (auto i = pVec.cbegin(); i != pVec.cend(); ++i) {
		cout << (*i)->net_price(70) << endl;
	}

	Basket total;
	total.addItem(a);
	total.addItem(b);

	total.total_receipt(cout);

	return 0;
}