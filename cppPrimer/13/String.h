#include <iostream>
#include <memory>

using namespace std;

class String {

public:
	String() : String("") {}
	String(const char*);
	String(const String &);
	String& operator=(const String &);
	~String();

	String(String &&) noexcept;
	String& operator=(String &&) noexcept;

	size_t length() { return pEnd - pBeg - 1; }
	size_t size() { return pEnd - pBeg; }
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