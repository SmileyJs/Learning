#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
	Employee () {
		id = increment++;
	}
	Employee (const string &s) : name(s) {
		id = increment++;
	}

	// In this case, we don't need to implement copy_assignment operator and copy_constructor.
	// because each employee can not be identical. 
	Employee (const Employee &c) {
		id = increment++;
	}
	Employee& operator= (const Employee &c) {
		id = increment++;
		return *this;
	}

	string name;
	int id;
	static int increment;
};

// initialise need type specifier here? why?
int Employee::increment = 0;

int
main(int argc, char const *argv[])
{
	Employee a, b = a;
	Employee *c = new Employee(a);
	cout << a.id << endl;
	cout << b.id << endl;
	cout << c->id << endl;

	*c = b;
	cout << c->id << endl;

	delete c;

	return 0;
}