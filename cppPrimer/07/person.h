#include <iostream>

using std::string;
using std::istream;
using std::ostream;

struct Person;
istream& read(istream &, Person &);

struct Person {
	Person() = default;
	Person(const string sname, const string saddress) :
		name(sname), address(saddress) { };
	Person(istream &is) {
		read(is, *this);
	}
public:
	const string& getName() const {return name;};
	const string& getAddress() const {return address;};
	string name;
	string address;
};

// const &string Person::getName() const {
// 	return name;
// }
// Why compile error?? for "expected initializer before ‘Person’".
// const &string Person::getAddress() const {
// 	return address;
// }

istream &read(istream &is, Person &item) {
	is >> item.name >> item.address;
	return is;
}

ostream &printf(ostream &os, const Person &item) {
	os << item.name << " " << item.address;
	return os;
}