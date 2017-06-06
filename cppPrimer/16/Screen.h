#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T> class Screen;

template <typename T> class WindowsManager
{
public:
	using screenIndex = vector<Screen<T>>::size_type;

	screenIndex addScreen(const Screen<T>&);
	void clear(screenIndex);
private:
	vector<Screen<T>> screens;
};

template <typename T> class Screen
{
public:
	using pos = string::size_type;
	friend void WindowsManager<T>::clear(WindowsManager<T>::screenIndex);

	Screen() : m_pData(make_shared<vector<T>>()) {}
	Screen(pos i, pos j) : wd(i), ht(j), m_pData(make_shared<vector<T>>()) {}
	Screen(pos i, pos j, const T& c) : wd(i), ht(j), m_pData(make_shared<vector<T>>(c)) {}

	const T& get(pos);
	const T& get(pos, pos);

	Screen& set(const T&);
	Screen& set(pos, pos, const T&);

	Screen& move(pos, pos);
	Screen& display();

private:
	void do_display() {
		cout << m_pData->at[cursor] << endl;
	}

	pos wd = 0;
	pos ht = 0;
	pos cursor = 0;
	shared_ptr<vector<T>> m_pData;
};

template <typename T>
const T& Screen<T>::get(pos cursor)
{
	return m_pData->at[cursor];
}

template <typename T>
const T& Screen<T>::get(pos x, pos y)
{
	return m_pData->at[wd*(y-1) + x];
}

template <typename T>
Screen<T>& Screen<T>::set(const T& c)
{
	m_pData->at[cursor] = c;
}

template <typename T>
Screen<T>& Screen<T>::set(pos x, pos y, const T& c)
{
	m_pData->at[wd*(y - 1) + x] = c;
}

template <typename T>
Screen<T>& Screen<T>::move(pos x, pos y)
{
	cursor = wd*(y - 1) + x;
	return *this;
}

template <typename T>
Screen<T>& Screen<T>::display()
{
	do_display();
	return *this;
}

template <typename T>
WindowsManager<T>::screenIndex
WindowsManager<T>::addScreen(const Screen<T>& s)
{
	screens.push_back(s);
	return screens.size() - 1;
}

template <typename T>
void
WindowsManager<T>::clear(WindowsManager<T>::screenIndex index)
{
	Screen<T>& s = screens[index];
	s.m_pData->clear();
}