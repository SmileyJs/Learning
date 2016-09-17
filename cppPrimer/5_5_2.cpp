#include <iostream>
#include <string>

using namespace std;

int 
main(int argc, char* argv[]) 
{
	string str = "";
	do {
		str = "";
		cout << "Please input two number!" << endl;
		int value1 = 0, value2 = 0;
		if (cin >> value1 >> value2) {
			cout << "The sum of" << value1 << " and " << value2 << " is " << value1 + value2 << endl;
			cout << "Try again? (Y/N)" << endl;
			cin >> str;
		}
	}
	while (!str.empty() && str[0] == 'Y');

	return 0;
}