#include <iostream>

#include <stdint.h>


int
main(void) 
{
	printf("please input a letter\n");

	char c;

	scanf("%c", &c);

	if (c >= 'A' && c <= 'Z') {
		printf("%c\n", c | 0x20);			
	}
	else if (c >= 'a' && c <= 'z') {
		printf("%c\n", c & 0xdf);
	}
	else {
		printf("input error!\n");
	}

	return 0;
}
