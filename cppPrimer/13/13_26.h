#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class ConstStrBlobPtr;

class StrBlob {
public:
	using size_type = vector<string>::size_type;
	friend class ConstStrBlobPtr;

	StrBlob() : pData(make_shared<vector<string>>()) {}
	StrBlob(vector<string> &s) : pData(make_shared<vector<string>>(s)) {}
	explicit StrBlob(initializer_list<string> il) : pData(make_shared<vector<string>>(il)) {}

	StrBlob(const StrBlob &s) : pData(make_shared<vector<string>>(*s.pData)) {}
	StrBlob &operator=(const StrBlob &c) {
		pData = make_shared<vector<string>>(*c.pData);
		return *this;
	}

	bool empty() { return pData->empty(); }
	size_type size() { return pData->size(); }

	void pop_back() { pData->pop_back(); }
	void push_back(const string &s) { pData->push_back(s); }

	const string &front();
	const string &back();

	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;

private:
	shared_ptr<vector<string>> pData;
	void check(size_type, const string &) const;
};

void
StrBlob::check(size_type i, const string &msg) const
{
	if (i > pData->size()) {
		throw out_of_range(msg);
	}
}

const string &
StrBlob::front()
{
	check(0, "out of range front");
	return pData->front();
}

const string &
StrBlob::back()
{
	check(0, "out of range back");
	return pData->back();
} 

class ConstStrBlobPtr {
public:
	using size_type = vector<string>::size_type;

	ConstStrBlobPtr() : crt(0) {}
	ConstStrBlobPtr(const StrBlob &s, size_type i = 0) : wP(s.pData), crt(i) {}

	const string &deRef() const;
	ConstStrBlobPtr &incr();

	bool operator!=(const ConstStrBlobPtr &p) { return crt != p.crt; } 

private:
	shared_ptr<vector<string>> check(size_type, const string &) const;
	weak_ptr<vector<string>> wP;
	size_type crt;
};

shared_ptr<vector<string>>
ConstStrBlobPtr::check(size_type i, const string &msg) const
{
	auto ret = wP.lock();

	if (!ret) {
		throw runtime_error("unbound ConstStrBlobPtr!");
	}
	else {
		if (i > ret->size())
			throw out_of_range(msg);
	}

	return ret;
}

const string &
ConstStrBlobPtr::deRef() const
{
	auto p = check(crt, "deReference past end!");
	return (*p)[crt];
}

ConstStrBlobPtr &
ConstStrBlobPtr::incr()
{
	check(crt, "increment past end!");
	++crt;
	return *this;
}

ConstStrBlobPtr 
StrBlob::begin() const
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr
StrBlob::end() const
{
	return ConstStrBlobPtr(*this, pData->size());
}