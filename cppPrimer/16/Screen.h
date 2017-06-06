#include <iostream>
#include <string>

using namespace std;

using pos = string::size_type;

template <pos W, pos H> class Screen;

template <pos W, pos H> ostream& operator<<(ostream&, const Screen<W, H>&);
template <pos W, pos H> istream& operator>>(istream&, Screen<W, H>&);

template <pos W, pos H> class Screen
{
public:
	friend ostream& operator<<<W, H>(ostream&, const Screen<W, H>&);
	friend istream& operator>><W, H>(istream&, Screen<W, H>&);

	Screen() {}
	Screen(char c) : content(W*H, c) {}

	char get() const;
	char get(pos, pos) const;

	Screen& set(char);
	Screen& set(pos, pos, char);

	Screen& move(pos, pos);

private:
	pos cursor = 0;
	string content;
};

template <pos W, pos H>
char Screen<W, H>::get() const
{
	return content[cursor];
}

template <pos W, pos H>
char Screen<W, H>::get(pos x, pos y) const
{
	return content[W*y + x];
}

template <pos W, pos H>
Screen<W, H>& Screen<W, H>::set(char c)
{
	content[cursor++] = c;
	cursor = (cursor > W*H ? W*H : cursor);
	return *this;
}

template <pos W, pos H>
Screen<W, H>& Screen<W, H>::set(pos x, pos y, char c)
{
	content[W*y + x] = c;
	return *this;
}

template <pos W, pos H>
Screen<W, H>& Screen<W, H>::move(pos x, pos y)
{
	cursor = W*y + H;
	return *this;
}

template <pos W, pos H>
ostream& operator<<(ostream& os, const Screen<W, H>& lhs)
{
	for (pos i = 0; i != H; ++i) {
		for (pos j = 0; j != W; ++j) {
			os << lhs.get(i, j);
		}
		os << endl;
	}

	return os;
}

template <pos W, pos H>
istream& operator>>(istream& is, Screen<W, H>& lhs)
{
	string input;
	is >> input;

	for (auto c : input) {
		lhs.set(c);
	}

	return is;
}