#include <iostream>

using namespace std;

template <typename T, unsigned sz>
void
print(const T (&ptr)[sz])
{
	for (auto i : ptr) {
		cout << i << endl;
	}
}

int
main(int argc, char const *argv[])
{
	char a[6] = {'a', 'b', 'c', 'd', 'e'};
	print(argv);

	int b[5] = {1, 2, 3, 4, 5};
	print(b);

	string c[5] = {"11", "22", "33", "44"}; 
	print(c);	

	return 0;
}