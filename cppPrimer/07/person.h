
using std::string;

struct Person {

public:
	const string& getName() const;
	const string& getAddress() const;

	string name;
	string address;
};

const string
Person::getName() const {
	return name;
}

const string
person::getAddress() const {
	return address;
}