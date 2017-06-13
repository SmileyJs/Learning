#include <iostream>
#include <utility>
#include <memory>

using namespace std;

template <typename T> class Vec
{
public:
	Vec() : element(nullptr), firstFree(nullptr), cap(nullptr) {};
	Vec(const Vec<T>&);
	Vec(Vec<T>&&) noexcept;
	explicit Vec(initializer_list<T>);

	~Vec() { free(); }
	
	size_t size() const { return firstFree - element; }
	size_t capacity() const { return cap - element; }

	Vec<T>& operator=(const Vec<T>&);
	T& operator[](size_t n) const { return *(element + n); };

	const T* begin() const { return element; }
	const T* end() const { return firstFree; }

	void reserve(size_t);
	void resize(size_t, const T& t = T());

private:
	pair<T*, T*> allocNCopy(const T*, const T*);
	void checkNAlloc();
	void allocNMove(size_t);
	void free();
	void reAllocate();

	allocator<T> alloc;
	T* element;
	T* firstFree;
	T* cap;
};

template <typename T>
void Vec<T>::checkNAlloc()
{
	if (size() == capacity())
		reAllocate();
}

template <typename T>
void Vec<T>::free()
{
	if (element) {
		while(firstFree != element) {
			alloc.destroy(--firstFree);
		}
		alloc.deallocate(element, capacity());
	}

	element = firstFree = cap = nullptr;
}

template <typename T>
void Vec<T>::reAllocate()
{
	auto newCap = size() ? size()*2 : 1;
	allocNMove(newCap);
}

template <typename T>
void Vec<T>::allocNMove(size_t newCap)
{
	auto newData = alloc.allocate(newCap);

	auto dest = newData;
	auto elem = element;

	for (auto i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}

	free();

	element = newData;
	firstFree = dest;
	cap = element + newCap;
}

template <typename T>
pair<T*, T*> Vec<T>::allocNCopy(const T* b, const T* e)
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

template <typename T>
Vec<T>::Vec(const Vec<T>& v)
{
	auto data = allocNCopy(v.begin(), v.end());

	element = data.first;
	firstFree = cap = data.second;
}

template <typename T>
Vec<T>::Vec(Vec<T>&& v) noexcept
{
	if (this != &v) {
		free();

		element = v.element;
		firstFree = v.firstFree;
		cap = v.cap;

		v.element = v.firstFree = v.cap = nullptr;
	}
}

template <typename T>
Vec<T>::Vec(initializer_list<T> il)
{
	auto data = allocNCopy(il.begin(), il.end());

	element = data.first;
	firstFree = cap = data.second;
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec<T>& v)
{
	auto data = allocNCopy(v.begin(), v.end());

	element = data.first;
	firstFree = cap = data.second;

	return *this;	
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
	if (n < size()) {
		while (n < size()) {
			alloc.destroy(--firstFree);	
		}
	}
	else if (n > size()) {
		reserve(n);
		while (n > size()) {
			alloc.construct(firstFree++, t);
		}
	}
}