#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
#include <algorithm>

using namespace std;

class StrVec {
public:
	StrVec() : elements(nullptr), firstFree(nullptr), cap(nullptr) {}
	StrVec(const StrVec &);
	explicit StrVec(initializer_list<string> il);
	StrVec &operator=(const StrVec &);
	~StrVec();

	StrVec(StrVec &&) noexcept;
	StrVec& operator=(StrVec &&) noexcept;

	string *begin() const { return elements; }
	string *end() const { return cap; }

	void push_back(const string &);

	size_t size() { return firstFree - elements; }
	size_t capacity() { return cap - elements; }
	void reserve(size_t);
	void resize(size_t, const string &t = "");

	const string & at(size_t pos) { return *(elements + pos); }

private:
	allocator<string> alloc;
	string *elements;
	string *firstFree;
	string *cap;

	pair<string *, string *> allocNCopy(const string *, const string *);
	void allocNMove(size_t);
	void chkNAllocate();
	void free();
	void reallocate();
};

StrVec::StrVec(const StrVec &c)
{
	auto data = allocNCopy(c.begin(), c.end());

	elements = data.first;
	firstFree = data.second;
	cap = data.second;
}

StrVec::StrVec(initializer_list<string> il)
{
	auto data = allocNCopy(il.begin(), il.end());

	elements = data.first;
	firstFree = data.second;
	cap = data.second;
}

StrVec &
StrVec::operator=(const StrVec &c)
{
	auto data = allocNCopy(c.begin(), c.end());

	free();

	elements = data.first;
	firstFree = data.second;
	cap = data.second;

	return *this;
}

StrVec::~StrVec()
{
	free();
}

StrVec::StrVec(StrVec &&c) noexcept
	: elements(c.elements)
	, firstFree(c.firstFree)
	, cap(c.cap)
{
	c.elements = nullptr;
	c.firstFree = nullptr;
	c.cap = nullptr;
}

StrVec &
StrVec::operator=(StrVec &&c) noexcept
{
	if (this != &c) {
		free();
		elements = c.elements;
		firstFree = c.firstFree;
		cap = c.cap;

		c.elements = nullptr;
		c.firstFree = nullptr;
		c.cap = nullptr;
	}

	return *this;
}

void
StrVec::chkNAllocate()
{
	if (size() == capacity())
		reallocate();
}

void
StrVec::free()
{
	if (elements) {
		// while (firstFree != elements) {
		// 	alloc.destroy(--firstFree);
		// }

		// 13_43
		for_each (elements, firstFree, [this](string &p) {
			alloc.destroy(&p);
		});

		alloc.deallocate(elements, cap - elements);
	}
}

void
StrVec::reallocate()
{
	auto newCapacity = size() ? size()*2 : 1;
	allocNMove(newCapacity);
}

pair<string *, string *>
StrVec::allocNCopy(const string *b,const string *e)
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(make_move_iterator(b), make_move_iterator(e), data)};
}

void
StrVec::allocNMove(size_t n)
{
	auto newData = alloc.allocate(n);

	auto dest = newData;
	auto elem = elements;

	// for (auto i = 0; i != size(); ++i) {
	// 	alloc.construct(dest++, std::move(*elem++));
	// }

	free();

	elements = newData;
	firstFree = dest;
	cap = elements + n;
}

void
StrVec::push_back(const string &s)
{
	chkNAllocate();
	alloc.construct(firstFree++, s);
}

void
StrVec::reserve(size_t n)
{
	while (capacity() < n) {
		allocNMove(n);
	}
}

void
StrVec::resize(size_t n, const string &t)
{
	if (n > size()) {
		reserve(n);
		while (size() < n) {
			alloc.construct(firstFree++, t);
		}
	}
	else if (n <  size()) {
		while (size() > n) {
			alloc.destroy(--firstFree);
		}
	}
}