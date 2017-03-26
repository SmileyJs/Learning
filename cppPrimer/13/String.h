#include <iostream>
#include <memory>

using namespace std;

class String {

public:
	String() : pBeg(nullptr), pEnd(nullptr) {}
	String(const char*);
	String(String &);
	String& operator=(const String &);
	~String();

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
	const char *s = p;
	while (*s) ++s;

	auto str = allocNCopy(p, s + 1);
	pBeg = str.first;
	pEnd = str.second;
}

String::String(String &c)
{
	auto str = allocNCopy(c.pBeg, c.pEnd);

	pBeg = str.first;
	pEnd = str.second;
}

String&
String::operator=(const String &c)
{
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
	return {str, uninitialized_copy(b, e, str)};
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