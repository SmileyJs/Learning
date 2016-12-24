#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Screen;

class Window_mgr {
	typedef vector<Screen>::size_type screenIndex;
public:
	void clear(screenIndex);
	screenIndex addScreen(const Screen &);

private:
	vector<Screen> screens;
};

class Screen {
	friend void Window_mgr::clear(screenIndex);
	using pos = string::size_type;
public:
	Screen() = default;
	Screen(pos wd, pos ht) : width(wd), height(ht), content(wd*ht, ' ') {};
	Screen(pos wd, pos ht, char c) : width(wd), height(ht), content(wd*ht, c) {};

	char get(pos cursor) const;
	char get(pos x, pos y) const;
	Screen &move(pos x, pos y);
	Screen &set(char c);
	Screen &set(pos x, pos y, char c);
	Screen &display();
	const Screen &display() const;
	pos size() const;

private:
	void do_display() const {
		cout << content;
	};

	pos width = 0, height = 0;
	pos cursor = 0;
	string content;
};

char Screen::get(pos cursor) const 
{
	return content[cursor];
}

char Screen::get(pos x, pos y) const
{
	return content[width*y + x];
}

Screen &Screen::move(pos x, pos y) 
{
	cursor = x*width + y;
	return *this;
}

Screen &Screen::set(char c)
{
	content[cursor] = c;
	return *this;
}

Screen &Screen::set(pos x, pos y, char c)
{
	content[y*width + x] = c;
	return *this;
}

Screen &Screen::display()
{
	do_display();
	return *this;
}

const Screen &Screen::display() const
{
	do_display();
	return *this;
}

Screen::pos Screen::size() const {
	return height * width;
}

void Window_mgr::clear(screenIndex index) {
	Screen &s = screens[index];
	s.content = string(s.width*s.height, ' ');
}

Window_mgr::screenIndex
Window_mgr::addScreen(const Screen &s) {
	screens.push_back(s);
	return screens.size() - 1;
}