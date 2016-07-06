#include <iostream>

using namespace std;

int main()
{
	int i = 100;
	int j = 0;

	for (int i = 0; i != 10; ++i)
		j += i;

	cout << "j = " << j  << " i = " << i << endl;

	return 0;
}
