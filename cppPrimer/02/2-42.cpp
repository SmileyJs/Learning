#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
#if 0
	int i = -1, &r = 0;
	int i2 = 4;
	int *const p2 = &i2;
	
	const int i = -1, &r = 0;

	const int *const p3 = &i2;
	const int *p1 = &i2;

	const int &const r2 = 4;

	const int i5 = i; const int &r1 = i;
#endif

//	int i, *const cp;

	const int i = 5;
	int a = 6;

	const int &r = a;

//	i = r;

//	cout << "i = " << i << endl;	

//	int *p1 = &i;

	const int *const p3 = &i;

	cout << "p3 = " << p3 << endl;

//	cout << "p1 = " << p1 << "p3 = " << p3 << endl;

//	p1 = &i;

//	cout << "p1 = " << p1 << endl;

	const int *p4, *const p5 = &i;

	p4 = p5;

//	int *p6 = p5; 	

	return 0;
}
