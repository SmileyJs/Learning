#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int
main(void)
{
	cout << "Please input some integer!" << endl;

	int i;

	while (cin >> i && i != 42) {
		cout << "haha" << endl;
	}

	return 0;
}
