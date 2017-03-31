#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
	friend bool operator<(const HasPtr &, const HasPtr &);
	
	HasPtr(const string &s = string(), int n = 0) : ps(new string(s)), i(n) {}
	HasPtr(const HasPtr &);
	HasPtr(HasPtr &&) noexcept;

	HasPtr &operator=(HasPtr);
	// HasPtr &operator=(const HasPtr &);
	// HasPtr &operator=(HasPtr &&) noexcept;

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
	// cout << "HasPtr::swap() begin--left: " << *lhs.ps << lhs.i << " right: " << *rhs.ps << rhs.i << endl;
	// using std::swap;
	std::swap(lhs.ps, rhs.ps);
	std::swap(lhs.i, rhs.i);
	// cout << "HasPtr::swap() end--left: " << *lhs.ps << lhs.i << " right: " << *rhs.ps << rhs.i << endl;
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
	// cout << "HasPtr::HasPtr(const HasPtr &c) " << *c.ps << c.i << endl;
}

HasPtr::HasPtr(HasPtr &&c) noexcept
	: ps(c.ps)
	, i(c.i)
{
	// cout << "HasPtr::HasPtr(HasPtr &&c) "  << *c.ps << c.i << endl;
	c.ps = nullptr;
}

HasPtr &
HasPtr::operator=(HasPtr c)
{
	// cout << "HasPtr &operator=(HasPtr c) " << *c.ps << c.i << endl;
	swap(*this, c);
	return *this;
}	

// HasPtr &
// HasPtr::operator=(const HasPtr &cp) 
// {
// 	// cout << "HasPtr::operator=(const HasPtr &cp)" << *cp.ps << cp.i << endl;
// 	string *newPs = new string(*cp.ps);
// 	// need to delete the orgin string
// 	delete ps;
// 	ps = newPs;
// 	i = cp.i;

// 	return *this;
// }

// HasPtr &
// HasPtr::operator=(HasPtr &&c) noexcept
// {
// 	// cout << "HasPtr::operator=(HasPtr &&c)" << *c.ps << c.i << endl;

// 	if (this != &c) {
// 		delete ps;

// 		ps = c.ps;
// 		i = c.i;

// 		c.ps = nullptr;
// 	}

// 	return *this;
// }