#include <iostream>
#include <memory>

using namespace std;

class String {
	friend ostream& operator<<(ostream&, const String&);
	friend bool operator==(const String&, const String&);
	friend bool operator<(const String&, const String&);
public:
	String() : String("") {}
	String(const char*);
	String(const String &);
	String& operator=(const String &);
	~String();

	String(String &&) noexcept;
	String& operator=(String &&) noexcept;
	char& operator[](size_t);
	const char& operator[](size_t) const;

	size_t length() { return pEnd - pBeg - 1; }
	size_t size() const { return pEnd - pBeg; }
	const char* c_str() { return pBeg; }

private:
	pair<char *, char *> allocNCopy(const char *, const char *);
	void free();

	allocator<char> alloc;
	char *pBeg;
	char *pEnd;
};

String::String(const char *p)
{
	cout << "String::String(const char *)" << endl;

	const char *s = p;
	while (*s) ++s;

	auto str = allocNCopy(p, s + 1);
	pBeg = str.first;
	pEnd = str.second;
}

String::String(const String &c)
{
	cout << "String::String(String &c)" << endl;

	auto str = allocNCopy(c.pBeg, c.pEnd);

	pBeg = str.first;
	pEnd = str.second;
}

String&
String::operator=(const String &c)
{
	cout << "String::operator=" << endl;

	auto str = allocNCopy(c.pBeg, c.pEnd);

	free();

	pBeg = str.first;
	pEnd = str.second;

	return *this;
}

String::~String()
{
	free();
}

pair<char *, char *>
String::allocNCopy(const char *b, const char *e)
{
	auto str = alloc.allocate(e - b);
	return {str, uninitialized_copy(make_move_iterator(b),
		make_move_iterator(e), str)};
}

void
String::free()
{
	if (pBeg) {
		for (auto i = pEnd; i != pBeg;)
			alloc.destroy(--i);
		alloc.deallocate(pBeg, pEnd - pBeg);
	}
}

String::String(String &&c) noexcept
	: pBeg(c.pBeg)
	, pEnd(c.pEnd)
{
	cout << "String::String(String &&c) noexcept" << endl;

	c.pBeg = nullptr;
	c.pEnd = nullptr;
}

String&
String::operator=(String &&c) noexcept
{
	cout << "String::operator=(String &&c) noexcept" << endl;

	if (this != &c) {
		free();
		pBeg = c.pBeg;
		pEnd = c.pEnd;

		c.pBeg = nullptr;
		c.pEnd = nullptr;
	}

	return *this;
}

ostream&
operator<<(ostream& os, const String& s)
{
	cout << __PRETTY_FUNCTION__ << endl;

	for (auto  i = s.pBeg; i != s.pEnd; ++i) {
		os << *i;
	}

	return os;
}

bool
operator==(const String& lhs, const String& rhs)
{
	cout << __PRETTY_FUNCTION__ << endl;

	return (lhs.size() == rhs.size() && std::equal(lhs.pBeg, lhs.pEnd, rhs.pBeg));
}

bool
operator!=(const String& lhs, const String& rhs)
{
	cout << __PRETTY_FUNCTION__ << endl;

	return !(lhs == rhs);
}

bool
operator<(const String& lhs, const String& rhs)
{
	cout << __PRETTY_FUNCTION__ << endl;

	return std::lexicographical_compare(lhs.pBeg, lhs.pEnd, rhs.pBeg, rhs.pEnd);
}

bool
operator>(const String& lhs, const String& rhs)
{
	cout << __PRETTY_FUNCTION__ << endl;

	return rhs < lhs;
}

bool
operator<=(const String& lhs, const String& rhs)
{
	cout << __PRETTY_FUNCTION__ << endl;

	return !(rhs < lhs);
}

bool
operator>=(const String& lhs, const String& rhs)
{
	cout << __PRETTY_FUNCTION__ << endl;

	return !(lhs < rhs);
}

char&
String::operator[](size_t n)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return pBeg[n];
}

const char&
String::operator[](size_t n) const
{
	cout << __PRETTY_FUNCTION__ << endl;
	return pBeg[n];
}