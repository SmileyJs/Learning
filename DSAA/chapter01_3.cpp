#include <stdio.h>
#include <stdlib.h> 


void printDigit(int n)
{
	printf("%d", n);
}

void printOut(int n)
{
	if (n >= 10) {
		printOut(n/10);
	}
    printDigit(n%10);    
}

int
main(int argc, char const *argv[])
{
	if (2 != argc) {
		printf("argument error!\n");
		return -1;
	}

	int num = atoi(argv[1]);

    if (num < 0) {
        printf("-");
    }

	printOut(abs(num));

    printf("\n");   

	return 0;
}