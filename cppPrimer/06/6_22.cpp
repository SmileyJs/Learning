#include "chapter6.h"

int
main(int argc, char const *argv[])
{
	int i = 1, j = 2;
	cout << "Before swapPointer, i = " << i << " j = " << j << endl;
	int *a = &i, *b = &j;
	swapPointer(a, b);
	cout << "After swapPointer, i = " << *a << " j = " << *b << endl; 

	return 0;
}

void
swapPointer(int *&p, int *&q)
{
	auto tmp = p;
	p = q;
	q = tmp;
}

// #include <iostream>

// void swap(int*& lft, int*& rht)
// {
//     auto tmp = lft;
//     lft = rht;
//     rht = tmp;
// }

// int main()
// {
//     int i = 42, j = 99;
//     auto lft = &i;
//     auto rht = &j;
//     swap(lft, rht);
//     std::cout << *lft << " " << *rht << std::endl;
//     return 0;
// }