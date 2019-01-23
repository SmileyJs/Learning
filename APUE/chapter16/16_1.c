#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int
main(int argc, char const *argv[])
{
	uint32_t i = 0x01020304;
	unsigned char *cp = (unsigned char*)&i;

	printf("%c\n", *cp);

	printf("%p\n", &i);
	printf("%p\n", &cp);

	if (4 == *cp) {
		printf("big endian\n");
	}
	else if (1 == *cp) {
		printf("little endian\n");
	}
	else {
		printf("else\n");
	}

	return 0;
}