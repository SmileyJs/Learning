#include "chapter6.h"

int
main(int argc, char const *argv[])
{
	cout << factorial(atoi(argv[1])) << endl;;
	return 0;
}

int
factorial(int i) {
	if (i > 1) {
		// return factorial(--i)*i; // error,求值顺序不确定
		return factorial(i-1)*i;
	}
	else {
		return 1;
	}
}