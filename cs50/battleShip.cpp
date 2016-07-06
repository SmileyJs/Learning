#include <iostream>

using namespace std;

int
main(int argc, char* argv[])
{
	printf("\n   ");

	for (int i  = 0; i < 10; ++i) {
		printf("%d  ", i);
	}

	printf("\n");

	for (char c = 'A'; c < 'K'; c = char((int)c + 1)) {
		printf("%c", c);

		for (int i = 0; i < 10; ++i) {
			printf("  o");
		}

		printf("\n");
	}


	return 0;
}
