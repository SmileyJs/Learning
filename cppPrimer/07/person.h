#include <iostream>

using std::string;
using std::istream;
using std::ostream;

class Person;
istream& read(istream &, Person &);

class Person {
	friend istream &read(istream &, Person &);
	friend ostream &print(ostream &, const Person &);

public:
	Person() = default;
	Person(const string sname, const string saddress) :
		name(sname), address(saddress) { };
	Person(istream &is) {
		read(is, *this);
	}

	const string& getName() const {return name;};
	const string& getAddress() const {return address;};

private:
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

ostream &print(ostream &os, const Person &item) {
	os << item.name << " " << item.address;
	return os;
}