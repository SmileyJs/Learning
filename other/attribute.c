#include <stdlib.h>

void myPrint(const char *format, ...) __attribute__((format(printf, 1, 2)));

int
main(int argc, char const *argv[])
{
	myPrint("i=%d\n", 6);
	myPrint("i=%s\n", 6);
	myPrint("i=%s\n", "abc");
	myPrint("%s, %d, %d\n, 1, 2");

	return 0;
}