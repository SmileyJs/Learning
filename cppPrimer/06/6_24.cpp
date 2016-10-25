#include "chapter6.h"

int
main(int argc, char const *argv[])
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 
	int b[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
	int c[] = {0, 1, 2, 3, 4, 5, 6, 7};

	// print(a);
	print(b);
	// print(c);

	return 0;
}

void
print(const int (&ia)[10])
{
	for (size_t i = 0; i != 10; ++i) {
		cout << ia[i] << endl;
	}
}