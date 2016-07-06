#include <iostream>

using namespace std;

int main()
{
	cout << "Please input tow number:" << endl;

	int a = 0;
	int b = 0;

	cin >> a >> b;

	if (a > b) {
		int c = a;
		a = b;
		b = c;
	}
	
	while (a < b - 1) {
		-- b;
		cout << b << endl;
	}

	return 0;
}
