#include "chapter6.h"

int
main(int argc, char const *argv[])
{
	int i = 0;
	int j[2] = {0, 1};
	char str[9]= "Jsssssss";

	print(str);
	print(&i);
	print(j, size_t(2));
	print(begin(j), end(j));
	print(j);

	return 0;
}

void print(const int *p) 
{
	if (p) cout << *p << endl;
}

void print(const char *p)
{
	while (p && *p) {
		cout << *p++;;
	}
	cout << endl;
}

void print(const int *p, const int *q)
{
	while (p != q) {
		cout << *p++ << endl;
	}
}

void print(const int *p, size_t size) 
{
	for (size_t i = 0; i != size; ++i) {
		cout << p[i] << endl;
	}
}

void print(const int(&arr)[2])
{
	for (auto i : arr) {
		cout << i << endl;
	}
}