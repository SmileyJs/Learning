#include <iostream>
#include <string>

using namespace std;

int
main(int argc, char const *argv[])
{
	string rsp;

	do {
		cout << "Please input two string" << endl;
		string str1, str2;

		cin >> str1 >> str2;
		string output = str1.size() > str2.size() ? str1 : str2;
		cout << "The longer str is " << output << endl;

		cout << "Try again?(Y/N)" << endl;
		cin >> rsp;
	}
	while (!rsp.empty() && rsp[0] == 'Y');

	return 0;
}