#include <iostream>

using namespace std;

int main()
{
	int i  = 1, j = 2;

	int *p1 = NULL, *p2 = 0;

	p1 = &i;
	p2 = &j;

	p1 = &j;

	*p1 = 100;

	cout << "&p1 = " << p1 << " &p2 = " << p2 << endl;

	cout << "i = " << i << " *p1 = " << *p1 << endl;

	cout << "j = " << j << " *p2 = " << *p2 << endl; 

	return 0;
}

