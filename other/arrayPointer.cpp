#include <iostream>

using namespace std;

int
main(int argc, char const *argv[])
{
	// int v[2][10] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
	// 	{11, 12, 13, 14, 15, 16, 17, 18, 19, 20}};

	// int (*a)[10] = v;

	// cout << a << endl;
	// cout << *a << endl;
	// cout << **a << endl;
	// cout << **(a+1) << endl;
	// cout << *(*a+1) << endl;
	// cout << *(a[0] + 1) << endl;
	// cout << *(a[1]) << endl;
	// cout << *(*(a+1)) << endl;

	int p = 5, p2 = 6, *page, *page2;

	int Test[2][3] = {{1, 2, 3}, {4, 5, 6}};
	int Test2[3] = {1, 2, 3};

	page = &p;
	page2 = &p2;

	int (*A)[3] = &Test[1];
	int (*B)[3] = &Test2;

	cout << *page << endl;
	cout << (*A)[0] << (*A)[1] << (*A)[2] << endl;
	cout << (*B)[3] << endl;

	return 0;
}