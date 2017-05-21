#include <iostream>
#include <string>
#include <vector>
// #include <stdexcept>
#include <exception>
#include <memory>
#include <initializer_list>

using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
public:
	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator<(const StrBlob&, const StrBlob&);

	// using size_type = vector<string>::size_type;
	typedef vector<string>::size_type size_type;

	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;

	StrBlob();
	StrBlob(vector<string> &vec);
	explicit StrBlob(initializer_list<string> il);

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	string & front();
	string & back();
	// const string & front() const;
	// const string & back() const;
	string & front() const;
	string & back() const;
	void push_back(const string &s) const;
	void push_back(string &&) const;
	void pop_back();

	StrBlobPtr begin();
	StrBlobPtr end();

	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;

	unsigned count() const { return data.use_count(); }

	string& operator[](size_t);
	const string& operator[](size_t) const;

private:
	shared_ptr<vector<string>> data;
	void check(size_type t, const string &msg);
	void check(size_type t, const string &msg) const;
};

StrBlob::StrBlob()
{
	data = make_shared<vector<string>>();
}

StrBlob::StrBlob(vector<string> &s)
{
	data = make_shared<vector<string>>(s);
}

StrBlob::StrBlob(initializer_list<string> il)
{
	data = make_shared<vector<string>>(il);
}

void
StrBlob::check(size_type t, const string &msg)
{
	if (t > data->size()) {
		throw out_of_range(msg);
	}
}

void
StrBlob::check(size_type t, const string &msg) const
{
	if (t > data->size()) {
		throw out_of_range(msg);
	}
}

string &
StrBlob::front()
{
	check(0, "out_of_range_front");
	return data->front();
}

// const string &
// StrBlob::front() const
// {
// 	check(0, "out_of_range_const_front");
// 	return data->front();
// }

string &
StrBlob::front() const
{
	check(0, "out_of_range_front");
	return data->front();
}

string &
StrBlob::back()
{
	check(0, "out_of_range_back");
	return data->back();
}

// const string &
// StrBlob::back() const
// {
// 	check(0, "out_of_range_const_back");
// 	return data->back();
// }

string &
StrBlob::back() const
{
	check(0, "out_of_range_back");
	return data->back();
}

void
StrBlob::push_back(const string &s) const
{
	data->push_back(s);
}

void
StrBlob::push_back(string &&s) const
{
	data->push_back(std::move(s));
}

void
StrBlob::pop_back()
{
	check(0, "out_of_range_pop_back");
	data->pop_back();
}

class StrBlobPtr {
public:
	StrBlobPtr () : curr(0) {}
	StrBlobPtr (StrBlob &a , vector<string>::size_type sz = 0) : wPtr(a.data), curr(sz) {}

	string &deRef() const;
	StrBlobPtr &incr();

	bool operator!=(const StrBlobPtr &p) { return curr != p.curr; }
	unsigned count() const { return wPtr.use_count(); }
	string& operator[](size_t);
	const string& operator[](size_t) const;

	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);

	StrBlobPtr& operator-=(size_t);
	StrBlobPtr& operator+=(size_t);
	StrBlobPtr& operator-(size_t);
	StrBlobPtr& operator+(size_t);

private:	
	shared_ptr<vector<string>> check(vector<string>::size_type, const string &msg) const;
	weak_ptr<vector<string>> wPtr;
	vector<string>::size_type curr;
};

string &
StrBlobPtr::deRef() const
{
	auto p = check(curr, "deReference past end!");
	return (*p)[curr];
}

StrBlobPtr &
StrBlobPtr::incr()
{
	check(curr, "increment past end!");
	++curr;
	return *this;
}

shared_ptr<vector<string>>
StrBlobPtr::check(vector<string>::size_type i, const string &msg) const
{
	auto ret = wPtr.lock();

	if (!ret) {
		throw runtime_error("unbound StrBlobPtr");
	}
	else {
		if (i >= ret->size()) throw out_of_range(msg);
	}

	return ret;
}

StrBlobPtr
StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr
StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

class ConstStrBlobPtr {
public:
	using size_type = vector<string>::size_type;
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, size_type sz = 0) : wPtr(a.data), curr(sz) {}

	const string& deRef() const;
	ConstStrBlobPtr& incr();

	bool operator!=(const ConstStrBlobPtr &p) { return curr == p.curr; }
	const string& operator[](size_t) const;

private:
	shared_ptr<vector<string>> check(size_type sz, const string &msg) const;
	weak_ptr<vector<string>> wPtr;
	vector<string>::size_type curr;
};

shared_ptr<vector<string>>
ConstStrBlobPtr::check(size_type sz, const string &msg) const
{
	auto ret = wPtr.lock();

	if (!ret) {
		throw runtime_error("unbound StrBlobPtr");
	}
	else {
		if (sz >= ret->size()) 
			throw out_of_range(msg);
	}

	return ret;
}

const string &
ConstStrBlobPtr::deRef() const
{
	auto p = check(curr, "deReference past end!");
	// can not dereference weak_ptr here??
	return (*p)[curr];
}

ConstStrBlobPtr &
ConstStrBlobPtr::incr()
{
	check(curr, "increment past end!");
	++curr;
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
	return ConstStrBlobPtr(*this, data->size());
}

bool
operator==(const StrBlob& lhs, const StrBlob& rhs)
{
	return *lhs.data == *rhs.data;
}

bool
operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
	return !(lhs == rhs);
}

bool
operator<(const StrBlob& lhs, const StrBlob& rhs)
{
	cout << __PRETTY_FUNCTION__ << endl;

	return *lhs.data < *rhs.data;
}

bool
operator>(const StrBlob& lhs, const StrBlob& rhs)
{
	cout << __PRETTY_FUNCTION__ << endl;

	return rhs < lhs;
}

bool
operator<=(const StrBlob& lhs, const StrBlob& rhs)
{
	cout << __PRETTY_FUNCTION__ << endl;

	return !(rhs < lhs);
}

bool
operator>=(const StrBlob& lhs, const StrBlob& rhs)
{
	cout << __PRETTY_FUNCTION__ << endl;

	return !(lhs < rhs);
}

string&
StrBlob::operator[](size_t n)
{
	cout << __PRETTY_FUNCTION__ << endl;
	check(n, "out_of_range");
	return data->at(n);
}

const string&
StrBlob::operator[](size_t n) const
{
	cout << __PRETTY_FUNCTION__ << endl;
	check(n, "out_of_range");
	return data->at(n);
}

string&
StrBlobPtr::operator[](size_t n)
{
	cout << __PRETTY_FUNCTION__ << endl;
	auto p = check(n, "out_of_range");

	return (*p)[n];
}

const string&
StrBlobPtr::operator[](size_t n) const
{
	cout << __PRETTY_FUNCTION__ << endl;
	auto p = check(n, "out_of_range");

	return (*p)[n];
}

const string&
ConstStrBlobPtr::operator[](size_t n) const
{
	cout << __PRETTY_FUNCTION__ << endl;
	auto p = check(n, "out_of_range");

	return (*p)[n];
}

StrBlobPtr&
StrBlobPtr::operator++()
{
	cout << __PRETTY_FUNCTION__ << endl;

	check(curr, "increment past end of StrBlob");
	++curr;
	return *this;
}

StrBlobPtr&
StrBlobPtr::operator--()
{
	cout << __PRETTY_FUNCTION__ << endl;

	--curr;
	check(curr, "decrement past begin of StrBlob");
	return *this;
}

StrBlobPtr
StrBlobPtr::operator++(int)
{
	cout << __PRETTY_FUNCTION__ << endl;

	StrBlobPtr ret = *this;
	++*this;

	return ret;
}

StrBlobPtr
StrBlobPtr::operator--(int)
{
	cout << __PRETTY_FUNCTION__ << endl;

	StrBlobPtr ret = *this;
	--*this;

	return ret;
}

StrBlobPtr&
StrBlobPtr::operator+=(size_t n)
{
	cout << __PRETTY_FUNCTION__ << endl;

	curr += n;
	check(curr, "out of range+=.");

	return *this;
}

StrBlobPtr&
StrBlobPtr::operator-=(size_t n)
{
	cout << __PRETTY_FUNCTION__ << endl;

	curr -= n;
	check(curr, "out of range-=");

	return *this;
}

StrBlobPtr&
StrBlobPtr::operator+(size_t n)
{
	cout << __PRETTY_FUNCTION__ << endl;

	*this += n;

	return *this;
}

StrBlobPtr&
StrBlobPtr::operator-(size_t n)
{
	cout << __PRETTY_FUNCTION__ << endl;

	*this -= n;

	return *this;
}