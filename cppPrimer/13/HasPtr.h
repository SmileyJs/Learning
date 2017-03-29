#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
	friend bool operator<(const HasPtr &, const HasPtr &);
	
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &);
	// HasPtr(HasPtr &&);

	HasPtr &operator=(HasPtr);

	~HasPtr() { delete ps; }

	inline void swap(HasPtr &, HasPtr &);

	string &show() { return *ps; }

private:
	string *ps;
	int i;
};

void
HasPtr::swap(HasPtr &lhs, HasPtr &rhs)
{
	cout << "HasPtr::swap() begin--left: " << *lhs.ps << " right: " << *rhs.ps << endl;
	// using std::swap;
	std::swap(lhs.ps, rhs.ps);
	std::swap(lhs.i, rhs.i);
	cout << "HasPtr::swap() end--left: " << *lhs.ps << " right: " << *rhs.ps << endl;
}

bool
operator<(const HasPtr &lhs, const HasPtr &rhs)
{
	return *lhs.ps < *rhs.ps;
}

HasPtr::HasPtr(const HasPtr &c)
	: ps(new string(*c.ps))
	, i(c.i)
{
	cout << "HasPtr::HasPtr(const HasPtr &c)" << endl;
}

// HasPtr::HasPtr(HasPtr &&c)
// 	: ps(c.ps)
// 	, i(c.i)
// {
// 	cout << "HasPtr::HasPtr(HasPtr &&c)" << endl;
// 	c.ps = nullptr;
// }

HasPtr &
HasPtr::operator=(HasPtr c)
{
	cout << "HasPtr &operator=(HasPtr c)" << endl;
	swap(*this, c);
	return *this;
}

// HasPtr &
// HasPtr::operator=(const HasPtr &cp) {
// 	string *newPs = new string(*cp.ps);
// 	// need to delete the orgin string
// 	delete ps;
// 	ps = newPs;
// 	i = cp.i;

// 	return *this;
// }