#include <iostream>
#include <functional>
#include <utility>

using namespace std;

class Delete
{
public:	
	template <typename T> void operator()(T* p) {
		cout << __PRETTY_FUNCTION__ << endl;
		delete p;
	}
};

template <typename T>
class SharedPtr
{
public:
	SharedPtr(T* = nullptr,function<void(T*)> = Delete());
	SharedPtr(const SharedPtr<T> &);
	SharedPtr(SharedPtr<T>&&) noexcept;

	~SharedPtr() {
		decrement_destroy();
	}

	SharedPtr<T>& operator=(const SharedPtr<T>&);
	SharedPtr<T>& operator=(SharedPtr<T>&&) noexcept;

	operator bool() { return m_ptr ? true : false; }

	void reset();
	void reset(T*);
	void reset(T*, function<void(T*)>);
	
	SharedPtr<T>& swap(SharedPtr<T>&);

	size_t use_count() { return *m_pCount; }
	bool unique() { return 1 == *m_pCount; }
	T* get() const { return m_ptr; }
	T& operator*() { return *m_ptr; }
	T* operator->() { return & this->operator*(); }

private:
	void decrement_destroy();

	T* m_ptr = nullptr;
	size_t* m_pCount = new size_t(0);
	function<void(T*)> m_deleter{Delete()};
};

template <typename T>
SharedPtr<T>::SharedPtr(T* p, function<void(T*)> d)
{
	m_ptr = p;
	m_deleter = d;
	*m_pCount = 1;
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& lhs)
{
	m_ptr = lhs.m_ptr;
	m_pCount = lhs.m_pCount;
	m_deleter = lhs.m_deleter;

	++m_pCount;
}

template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T>&& rhs) noexcept
{
	m_ptr = rhs.m_ptr;
	m_pCount = rhs.m_pCount;
	m_deleter = std::move(rhs.m_deleter);

	rhs.m_ptr = nullptr;
	rhs.m_pCount = nullptr;
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& p)
{
	++ *p.m_pCount;

	decrement_destroy();

	m_ptr = p.m_ptr;
	m_pCount = p.m_pCount;
	m_deleter = p.m_deleter;

	return *this;
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T>&& p) noexcept
{
	cout << __PRETTY_FUNCTION__ << endl;

	if (&this != p) {
		decrement_destroy();

		swap(*this, p);
	}

	return *this;
}

template <typename T>
void SharedPtr<T>::decrement_destroy()
{
	if (m_ptr) {
		if (0 == -- *m_pCount) {
			m_deleter(m_ptr);
			delete m_pCount;
		}
		m_ptr = nullptr;
		m_pCount = nullptr;
	}
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::swap(SharedPtr<T>& lhs)
{
	using std::swap;

	swap(m_ptr, lhs.m_ptr);
	swap(m_pCount, lhs.m_pCount);
	swap(m_deleter, lhs.m_deleter);

	return *this;
}

template <typename T>
void SharedPtr<T>::reset()
{
	decrement_destroy();
}

template <typename T>
void SharedPtr<T>::reset(T* p)
{
	if (m_ptr != p) {
		decrement_destroy();

		m_ptr = p;
		m_pCount = new size_t(1);
	}
}

template <typename T>
void SharedPtr<T>::reset(T* p, function<void(T*)> d)
{
	reset(p);

	m_deleter = d;
}

template <typename T, typename D = Delete>
class UniquePtr
{
public:
	UniquePtr(T*);
	UniquePtr(T*, D);

	UniquePtr(UniquePtr<T, D>&) = delete;
	UniquePtr<T, D>& operator=(UniquePtr<T, D>&) = delete;

	UniquePtr(UniquePtr&&) noexcept;
	UniquePtr<T, D>& operator=(UniquePtr<T, D>&&) noexcept;

	~UniquePtr() {
		m_deleter(m_ptr);
	}

	void operator=(nullptr_t);

	UniquePtr<T, D>& swap(UniquePtr<T, D>& rhs);

	T* release();
	void reset();
	void reset(T*);
	void reset(nullptr_t);

	T* get() { return m_ptr; }
	operator bool() { return m_ptr ? true : false; }
	T& operator*() { return *m_ptr; }
	T* operator&() { return & this->operator*(); }

private:
	T* m_ptr = nullptr;
	Delete m_deleter{Delete()};
};

template <typename T, typename D>
UniquePtr<T, D>::UniquePtr(T* p)
{
	m_ptr = p;
	m_deleter = Delete();
}

template <typename T, typename D>
UniquePtr<T, D>::UniquePtr(T* p, D d)
{
	m_ptr = p;
	m_deleter = d;
}

template <typename T, typename D>
UniquePtr<T, D>::UniquePtr(UniquePtr<T, D>&& u) noexcept
{
	m_ptr = u.m_ptr;
	u.m_ptr = nullptr;
}

template <typename T, typename D>
UniquePtr<T, D>& UniquePtr<T, D>::operator=(UniquePtr<T, D>&& u) noexcept
{
	if (m_ptr != u.m_ptr) {
		m_deleter(m_ptr);
		m_ptr = u.m_ptr;
		m_deleter = u.m_deleter;
	}

	return *this;
}

template <typename T, typename D>
void UniquePtr<T, D>::operator=(nullptr_t)
{
	if (m_ptr) {
		m_deleter(m_ptr);
	
		m_ptr = nullptr;
	}
}

template <typename T, typename D>
UniquePtr<T, D>& UniquePtr<T, D>::swap(UniquePtr<T, D>& rhs)
{
	using std::swap;

	swap(m_ptr, rhs.m_ptr);
	swap(m_deleter, rhs.m_deleter);
}

template <typename T, typename D>
void UniquePtr<T, D>::reset()
{
	m_deleter(m_ptr);
	m_ptr = nullptr;
}

template <typename T, typename D>
void UniquePtr<T, D>::reset(T* p)
{
	m_deleter(m_ptr);
	m_ptr = p;
}

template <typename T, typename D>
void UniquePtr<T, D>::reset(nullptr_t)
{
	reset();
}

template <typename T, typename D>
T* UniquePtr<T, D>::release()
{
	T* ret = m_ptr;
	m_ptr = nullptr;
	return ret;
}