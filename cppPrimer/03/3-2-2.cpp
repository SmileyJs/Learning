#include <iostream>

using namespace std;

int main()
{
	string str1, str2, str3, str4;

//	while (cin >> str) {
//		cout << str << endl;
//	}

//	while (getline(cin, str)) {
//		cout << str << endl;
//	}

/*****3.4
	while (cin >> str1 >> str2) {
		if (str1 == str2) {
			cout << "str1 is equal to str2!" << endl;
		} else if (str1 < str2) {
			cout << str2 << endl;
		} else {
			cout << str1 << endl;
		}
	}
*/
/****3.4
	while (cin >> str1 >> str2) {
		if (str1.size() == str2.size()) {
			cout << "str1's length is equal to str2's" << endl;
		} else if (str1.size() < str2.size()) {
			cout << str2 << endl;
		} else {
			cout << str1 << endl;
		}
	}
*/

	str1 = "";
	str2 = "";	

	while (cin >> str1) {
		if (str2.empty()) {
			str2 += str1;
		} else {
			str2 += " " + str1;
		} 		
	}
		
	cout << "str2 = " << str2 << endl;

	return 0;
}
