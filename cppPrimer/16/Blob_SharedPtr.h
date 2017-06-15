#include <iostream>
#include <memory>
#include <vector>
#include <exception>
#include <algorithm>

#include "Ptr.h"

using namespace std;

template <typename T> class Blob;
template <typename T> class BlobPtr;
template <typename T> class ConstBlobPtr;

template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator!=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>=(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob
{
	friend class BlobPtr<T>;
	friend class ConstBlobPtr<T>;

	friend bool operator==<T>(const Blob<T>& lhs, const Blob<T>& rhs);
	friend bool operator!=<T>(const Blob<T>& lhs, const Blob<T>& rhs);
	friend bool operator< <T>(const Blob<T>& lhs, const Blob<T>& rhs);
	friend bool operator> <T>(const Blob<T>& lhs, const Blob<T>& rhs);
	friend bool operator<=<T>(const Blob<T>& lhs, const Blob<T>& rhs);
	friend bool operator>=<T>(const Blob<T>& lhs, const Blob<T>& rhs);

public:
	Blob();
	Blob(const Blob<T>&);
	Blob(initializer_list<T>);
	Blob(Blob<T>&&);
	template <typename I> Blob(const I, const I);

	T& front();
	T& back();

	bool empty() { return m_pData->empty(); }
	size_t size() { return m_pData->size(); }

	void push_back(const T& s) { m_pData->push_back(s); }
	void push_back(T&& s) { m_pData->push_back(std::move(s)); }
	void pop_back();

	BlobPtr<T> begin();
	BlobPtr<T> end();

	ConstBlobPtr<T> cbegin() const;
	ConstBlobPtr<T> cend() const;

	unsigned count() const { return m_pData.use_count(); }

	T& operator[](size_t n);
	const T& operator[](size_t) const;

	Blob<T>& operator=(const Blob<T>&);
	Blob<T>& operator=(Blob<T>&&);

private:
	SharedPtr<vector<T>> m_pData;
	void check(size_t, const string&);
};

template <typename T> Blob<T>::Blob()
{
	m_pData = make_shared<vector<T>>();
}

template <typename T> Blob<T>::Blob(const Blob<T>& lhs)
{
	m_pData = make_shared<vector<T>>(*lhs.m_pData);
}

template <typename T> Blob<T>::Blob(initializer_list<T> il)
{
	m_pData = make_shared<vector<T>>(il);
}

template <typename T> Blob<T>::Blob(Blob<T>&& rhs)
{
	m_pData = rhs.m_pData;
}

template <typename T>
template <typename I>
Blob<T>::Blob(const I b, const I e)
	: m_pData(make_shared<vector<T>>(b, e))
{
}

template <typename T>
void Blob<T>::check(size_t n, const string& msg)
{
	if (n >= m_pData->size())
		throw out_of_range(msg);
}

template <typename T> T& Blob<T>::front()
{
	check(0, "front out of range.");
	return m_pData->front();
}

template <typename T> T& Blob<T>::back()
{
	check(0, "back out of range.");
	return m_pData->back();
}

template <typename T> void Blob<T>::pop_back()
{
	check(0, "pop_back on an empty Blob.");
	m_pData->pop_back();
}

template <typename T>
BlobPtr<T> Blob<T>::begin()
{
	return BlobPtr<T>(*this);
}

template <typename T>
BlobPtr<T> Blob<T>::end()
{
	return BlobPtr<T>(*this, m_pData->size());
}

template <typename T>
ConstBlobPtr<T> Blob<T>::cbegin() const
{
	return ConstBlobPtr<T>(*this);
}

template <typename T>
ConstBlobPtr<T> Blob<T>::cend() const
{
	return ConstBlobPtr<T>(*this, m_pData->size());
}

template <typename T>
T& Blob<T>::operator[](size_t n)
{
	check(n, "operatpr[] out of range Blob.");
	return m_pData->at(n);
}

template <typename T>
const T& Blob<T>::operator[](size_t n) const
{
	check(n, "operator[] out of range Blob");
	return m_pData->at(n);
}

template <typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return *lhs.m_pData == *rhs.m_pData;
}

template <typename T>
bool operator!=(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return !(lhs == rhs);
}

template <typename T>
bool operator<(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T>
bool operator>(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return rhs < lhs; 
}

template <typename T>
bool operator<=(const Blob<T>& lhs, const Blob<T> rhs)
{
	return !(rhs < lhs);
}

template <typename T>
bool operator>=(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return !(lhs < rhs);
}

template <typename T>
Blob<T>& Blob<T>::operator=(const Blob<T>& lhs)
{
	m_pData = SharedPtr<vector<T>>(*lhs.m_pData);
	return *this;
}

template <typename T>
Blob<T>& Blob<T>::operator=(Blob<T>&& rhs)
{
	if (this != &rhs) {
		m_pData = rhs.m_pData;
		rhs.m_pData = nullptr;
	}

	return *this;
}

template <typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>=(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> class BlobPtr
{
	friend bool operator==<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
	friend bool operator!=<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
	friend bool operator< <T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
	friend bool operator> <T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
	friend bool operator<=<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
	friend bool operator>=<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
public:
	BlobPtr() : curr(0) {}
	BlobPtr(Blob<T>& b, size_t sz = 0) : m_ptr(b.m_pData), curr(sz) {}

	T& deref();
	BlobPtr<T>& incr();

	BlobPtr<T>& operator++();
	BlobPtr<T>& operator--();
	BlobPtr<T> operator++(int);
	BlobPtr<T> operator--(int);
	BlobPtr<T>& operator+=(size_t);
	BlobPtr<T>& operator-=(size_t);
	BlobPtr<T> operator+(size_t) const;
	BlobPtr<T> operator-(size_t) const;
	T& operator*();

private:
	shared_ptr<vector<T>> check(size_t, const string&);

	weak_ptr<vector<T>> m_ptr;
	size_t curr;
};

template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t sz, const string& msg)
{
	auto ret = m_ptr.lock();

	if (!ret) {
		runtime_error("unbound BlboPtr");
	}
	else if (sz >= ret->size()){
		throw out_of_range(msg);
	}

	return ret;
}

template <typename T>
T& BlobPtr<T>::deref()
{
	auto p = check(curr, "deref out of range BlobPtr");
	return (*p)[curr];
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::incr()
{
	check(curr, "incr out of range BlobPtr.");
	++curr;
	return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "BlobPtr ++ out of range");
	++curr;
	return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	--curr;
	check(curr, "BlobPtr -- out of range");
	return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	auto ret = *this;
	++*this;
	
	return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
	auto ret = *this;
	--curr;

	return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator+=(size_t n)
{
	curr += n;
	check(curr, "operator+= out of range BlobPtr");

	return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator-=(size_t n)
{
	curr -= n;
	check(curr, "operator-= out of range BlobPtr");

	return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator+(size_t n) const
{
	auto ret = *this;
	ret += n;

	return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator-(size_t n) const
{
	auto ret = *this;
	ret -= n;

	return ret;
}

template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return !(lhs == rhs);
}

template <typename T>
bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return lhs.curr < rhs.curr;
}

template <typename T>
bool operator>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return rhs < lhs;
}

template <typename T>
bool operator<=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return !(rhs < lhs);
}

template <typename T>
bool operator>=(const BlobPtr<T>&lhs, const BlobPtr<T>& rhs)
{
	return !(lhs < rhs);
}

template <typename T>
T& BlobPtr<T>::operator*()
{
	auto p = check(curr, "BlobPtr operator* out of range.");
	return (*p)[curr];
}

template <typename T>
bool operator==(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator!=(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator<(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator<=(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator>=(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);

template <typename T> class ConstBlobPtr
{
	friend bool operator==<T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
	friend bool operator!=<T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
	friend bool operator< <T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
	friend bool operator> <T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
	friend bool operator<=<T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
	friend bool operator>=<T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
public:
	ConstBlobPtr() : curr(0) {}
	ConstBlobPtr(const Blob<T>& b, size_t sz = 0) : m_ptr(b.m_pData), curr(sz) {}

	const T& deref() const;
	ConstBlobPtr<T>& incr();

	ConstBlobPtr<T>& operator++();
	ConstBlobPtr<T>& operator--();
	ConstBlobPtr<T> operator++(int);
	ConstBlobPtr<T> operator--(int);
	ConstBlobPtr<T>& operator+=(size_t);
	ConstBlobPtr<T>& operator-=(size_t);
	ConstBlobPtr<T> operator+(size_t);
	ConstBlobPtr<T> operator-(size_t);

private:
	shared_ptr<vector<T>> check(size_t, const string&) const;

	weak_ptr<vector<T>> m_ptr;
	size_t curr;
};

template <typename T>
shared_ptr<vector<T>> ConstBlobPtr<T>::check(size_t sz, const string& msg) const
{
	auto ret = m_ptr.lock();

	if (!ret) {
		runtime_error("unbound ConstBlobPtr.");
	}
	else if (sz >= ret->size()) {
		throw out_of_range(msg);
	}

	return ret;
}

template <typename T>
const T& ConstBlobPtr<T>::deref() const
{
	auto p = check(curr, "deref out of range ConstBlobPtr.");
	return (*p)[curr];
}

template <typename T>
ConstBlobPtr<T>& ConstBlobPtr<T>::incr()
{
	check(curr, "incr out of range ConstBlobPtr.");
	++curr;
	return *this;
}

template <typename T>
ConstBlobPtr<T>& ConstBlobPtr<T>::operator++()
{
	check(curr, "ConstBlobPtr operator++ out of range.");
	++curr;

	return *this;
}

template <typename T>
ConstBlobPtr<T>& ConstBlobPtr<T>::operator--()
{
	--curr;
	check(curr, "ConstBlobPtr operator-- out of range.");

	return *this;
}

template <typename T>
ConstBlobPtr<T> ConstBlobPtr<T>::operator++(int)
{
	auto ret = *this;
	++*this;

	return ret;
}

template <typename T>
ConstBlobPtr<T> ConstBlobPtr<T>::operator--(int)
{
	auto ret = *this;
	--*this;

	return ret;
}

template <typename T>
ConstBlobPtr<T>& ConstBlobPtr<T>::operator+=(size_t n)
{
	curr += n;
	check(curr, "ConstBlobPtr operator+= out of range.");

	return *this;
}

template <typename T>
ConstBlobPtr<T>& ConstBlobPtr<T>::operator-=(size_t n)
{
	curr -= n;
	check(curr, "ConstBlobPtr operator-= out of range.");

	return *this;
}

template <typename T>
ConstBlobPtr<T> ConstBlobPtr<T>::operator+(size_t n)
{
	auto ret = *this;
	*this += n;

	return ret;
}

template <typename T>
ConstBlobPtr<T> ConstBlobPtr<T>::operator-(size_t n)
{
	auto ret = *this;
	*this -= n;

	return ret;
}

template <typename T>
bool operator==(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
	return lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
	return !(lhs == rhs);
}

template <typename T>
bool operator<(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
	return lhs.curr < rhs.curr;
}

template <typename T>
bool operator>(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
	return rhs.curr < lhs.curr;
}

template <typename T>
bool operator<=(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
	return !(rhs.curr < lhs.curr);
}

template <typename T>
bool operator>=(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
	return !(lhs.curr < rhs.curr);
}