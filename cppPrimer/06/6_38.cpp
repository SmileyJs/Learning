#include "chapter6.h"

// 6_36
string (&func())[10];

// 6_37
typedef arrStr string[10];
attStr &func1();

string[10] str;
decltype(str) &func2();

auto func3()->string (&)[10];


int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) &arrPtr(int i)
{
	return (i % 2) ? odd : even;
}