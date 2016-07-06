#include <stdint.h>

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int
main(void)
{
	int n;
	do {
		printf("Please input a non-negative integer: ");
		scanf("%d", &n);
	}
	while (n < 0);

	for (int i = sizeof(int) * 8 - 1; i >= 0; --i) {
		int mask = 1 << i;
		if (mask & n) {
			printf("1");
		}
		else {
			printf("0");
		}
	}
	
	printf("\n");

	return 0;
}
