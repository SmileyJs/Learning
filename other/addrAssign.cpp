#include <iostream>

using namespace std;

struct S
{
	int i;
	int* p;
};

int
main(int argc, char const *argv[])
{
	S s;
	int *p = &s.i;

	printf("%p\n", p);

	p[0] = 4;
	printf("%d\n", p[0]);
	printf("%p\n", &p[0]);

	p[1] = 3;
	printf("%d\n", p[1]);
	printf("%p\n", &p[1]);

	p[2] = 6;
	printf("%d\n", p[2]);
	printf("%p\n", &p[2]);
	printf("%p\n", s.p);


	s.p = p;
	printf("%p\n", s.p);
	s.p[2] = 1;
	printf("%p\n", &s.i);
	printf("%p\n", s.p);
	printf("%p\n", s.p[0]);
	// printf("%d\n", s.p[2]);
	// s.p[0] = 2;
	// printf("%d\n", s.p[0]);
	// printf("%p\n", &s.p[0]);

	return 0;
}