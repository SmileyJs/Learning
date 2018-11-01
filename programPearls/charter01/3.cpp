#include <iostream>
#include <fstream>

#define N 			1000000
#define bitsPerWord 32
#define Mask 		0x1f
#define Shift 		5

int a[N/bitsPerWord + 1] = {0};

void set(int i)
{
	a[i >> Shift] |= (1 << (i & Mask)); 
}

int get(int i)
{
	return a[i >> Shift] & (1 << (i & Mask));
}

void clr(int i)
{
	a[i >> Shift] &= ~(1 << (i & Mask));
}

int
main(int argc, char const *argv[])
{
	std::ifstream file("./numbers.txt");

	if (!file) {
		std::cout << "file open failed!" << std::endl;
		return -1;
	}

	int num;

	while (file >> num) {
		if (get(num))
			printf("num %d exist\n", num);
		set(num);
	}

	for (int i = 0; i != N; ++i) 
		if (get(i)) printf("%d\n", i);

	return 0;
}