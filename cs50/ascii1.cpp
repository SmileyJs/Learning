#include <iostream>

using namespace std;

int
main(int argc, char* argv[])
{
/**
 *	for (int i = 65; i < 65 + 26; ++i) {
 *		printf("%c:%d\n", i, i);
 *	}
 *
 *	for (int i = 97; i < 97 + 26; ++i) {
 *		printf("%c:%d\n", i, i);
 *	}
 */

/**
 *	for (int i = 65; i < 65 + 26; ++i) {
 *		printf("%c  %d  %3d  %c\n", i, i, i + 32, i + 32);
 *	}
 */

	for (char c = 'A'; c <= 'Z'; c = char(int(c) + 1)) {
		printf("%c  %d\n", c, int(c));
	}

	return 0;
}
