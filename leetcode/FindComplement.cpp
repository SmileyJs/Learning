#include <iostream>
#include <vector>

using namespace std;

int
findComplement(int x)
{
	int mask = 1, tmp = x;

	while (tmp) {
		tmp >>= 1;
		mask <<= 1;
	}

	return x^(mask - 1);
}

void
print(int i)
{
	cout << i << endl;
	vector<int> v;
	while (i != 0) {
		v.insert(v.begin(), i & 1);
		i >>= 1;
	}

	for (auto i : v) {
		cout << i;
	}

	cout << endl;
}

int
main(int argc, char const *argv[])
{
	int i;
	cin >> i;

	print(i);

	print(findComplement(i));

	return 0;
}