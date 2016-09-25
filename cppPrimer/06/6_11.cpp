#include "chapter6.h"

int
main(int argc, char const *argv[])
{
	int i = 11;
	cout << "i = " << i << endl;
	reset(i);
	cout << "After reset i is " << i << endl;

	return 0;
}

void
reset(int &val) 
{
	val = 0;
}