#include <iostream>
#include <memory>
#include <utility>

using namespace std;

template <typename T> class Vec
{
public:
	Vec() : element(nullptr), firstFree(nullptr), cap(nullptr) {}
	Vec(const Vec<T>&);
	Vec(Vec<T>&&) noexcept;
	explicit Vec<T>(initializer_list<T>);

	~Vec() { free(); }
	
	Vec<T>& operator=(const Vec<T>&);
	Vec<T>& operator=(Vec<T>&&) noexcept;
	T& operator[](size_t);
	const T& operator[](size_t) const;

	T* begin() const { return element; }
	T* end() const { return firstFree; }

	size_t size() const { return firstFree - element; }
	size_t capacity() const { return cap - element; }

	void push_back(const T&);

	void reserve(size_t);
	void resize(size_t, const T&);

private:
	allocator<T> alloc;
	void checkNAlloc();
	void free();
	pair<T*, T*> allocNCopy(const T*, const T*);
	void reAllocate();
	void allocNMove(size_t);

	T* element;
	T* firstFree;
	T* cap;
};

template <typename T>
Vec<T>::Vec(const Vec<T>& v)
{
	auto data = allocNCopy(v.begin(), v.end());

	element = data.first;
	firstFree = cap = data.second;
}

template <typename T>
Vec<T>::Vec(Vec<T>&& v) noexcept
	: element(v.element)
	, firstFree(v.firstFree)
	, cap(v.cap)
{
	v.element = nullptr;
	v.firstFree = nullptr;
	v.cap = nullptr;
}

template <typename T>
Vec<T>& Vec<T>::operator=(Vec<T>&& v) noexcept
{
	if (this != &v) {
		free();
		element = v.element;
		firstFree = v.firstFree;
		cap = v.cap;

		v.element = nullptr;
		v.firstFree = nullptr;
		v.cap = nullptr;
	}

	return *this;
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec<T>& v)
{
	auto data = allocNCopy(v.begin(), v.end());

	free();

	element = data.first;
	cap = firstFree = data.second;

	return *this;
}

template <typename T>
Vec<T>::Vec(initializer_list<T> il)
{
	auto data = allocNCopy(il.begin(), il.end());

	element = data.first;
	firstFree = cap = data.second;
}

template <typename T>
void Vec<T>::free()
{
	if (element) {
		while (firstFree != element) {
			alloc.destroy(--firstFree);		
		}

		alloc.deallocate(element, capacity());
	}
}

template <typename T>
void Vec<T>::checkNAlloc()
{
	if (cap == firstFree) {
		reAllocate();
	}
}

template <typename T>
pair<T*, T*> Vec<T>::allocNCopy(const T* b, const T*e)
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::reAllocate()
{
	auto newCapacity = size() ? size()*2 : 1;
	allocNMove(newCapacity);
}

template <typename T>
void Vec<T>::allocNMove(size_t n)
{
	auto beg = alloc.allocate(n);

	auto dest = beg;
	auto elem = element;

	for (size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}

	free();

	element = beg;
	firstFree = dest; 
	cap = element + n;
}

template <typename T>
void Vec<T>::push_back(const T& lhs)
{
	checkNAlloc();
	alloc.construct(firstFree++, lhs);
}

template <typename T>
T& Vec<T>::operator[](size_t n)
{
	// return *(element+n);
	return element[n];
}

template <typename T>
const T& Vec<T>::operator[](size_t n) const
{
	return element[n];
}

template <typename T>
void Vec<T>::reserve(size_t n)
{
	if (capacity() < n) {
		allocNMove(n);
	}
}

template <typename T>
void Vec<T>::resize(size_t n, const T& t)
{
	if (size() > n) {
		while (size() > n) {
			alloc.destroy(--firstFree);
		}
	}
	else if (size() < n) {
		reserve(n);
		while (size() < n) {
			alloc.construct(firstFree++, t);
		}
	}
}