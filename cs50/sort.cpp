#include  <iostream>

using namespace std;

void swap(int &a, int &b);

int
main(void)
{
	int a[10] = {5, 7, 9, 2, 1, 4, 6, 3, 8, 0};

	/* bubble sort*/
/****
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10 - i - 1; ++j) {
			if (a[j] > a [j+1]) {
				swap(a[j], a[j+1]);
			}
		}
	}
 */
	/* select sort*/

	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 10; ++j) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}

	for (int i : a) {
		cout << i << endl;
	}

	return 0;
}

void
swap(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
	cout << "swaped" << b << " " << a  << endl;
}
