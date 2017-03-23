#include <iostream>
#include <string>
#include <memory>
#include <utility>

using namespace std;

class StrVec {
public:
	StrVec() : elements(nullptr), firstFree(nullptr), cap(nullptr) {}
	StrVec(const StrVec &);
	StrVec &operator=(const StrVec &);
	~StrVec();

	string *begin() const { return elements; }
	string *end() const { return cap; }

	void push_back(const string &);

	size_t size() { return firstFree - elements; }
	size_t capacity() { return cap - elements; }

private:
	static allocator<string> alloc;
	string *elements;
	string *firstFree;
	string *cap;

	pair<string *, string *> allocNCopy(const string *, const string *);
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
		while (firstFree != elements) {
			alloc.destroy(--firstFree);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

void
StrVec::reallocate()
{
	auto newCapacity = size() ? size()*2 : 1;
	auto newData = alloc.allocate(newCapacity);

	auto dest = newData;
	auto elem = elements;

	for (auto i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}

	free();

	elements = newData;
	firstFree = dest;
	cap = elements + newCapacity;
}

pair<string *, string *>
StrVec::allocNCopy(const string *b,const string *e)
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

void
StrVec::push_back(const string &s)
{
	chkNAllocate();
	alloc.construct(firstFree++, s);
}