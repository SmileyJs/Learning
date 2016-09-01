#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int
main(int argc, char const *argv[])
{
	string str;
	int aCnt;
	int eCnt;
	int iCnt;
	int oCnt;
	int uCnt;

	// while (getline(cin, str)) {
	// 	aCnt = 0;
	// 	eCnt = 0;
	// 	iCnt = 0;
	// 	oCnt = 0;
	// 	uCnt = 0;

	// 	for (string::iterator i = str.begin(); i != str.end(); ++i) {
	// 		if (*i == 'a') {
	// 			++aCnt;
	// 		}
	// 		else if (*i == 'e') {
	// 			++eCnt;
	// 		}
	// 		else if (*i == 'i') {
	// 			++iCnt;
	// 		}
	// 		else if (*i == 'o') {
	// 			++oCnt;
	// 		}
	// 		else if (*i == 'u') {
	// 			++uCnt;
	// 		}
	// 	}
	// 	cout << "a" << aCnt << "\t" << "e" << eCnt << "\t" << "i" << iCnt << "\t" << "o" << oCnt << "\t" << "u" << uCnt << endl; 
	// }

	aCnt = 0;
	eCnt = 0;
	iCnt = 0;
	oCnt = 0;
	uCnt = 0;

	char ch;
	while (cin >> ch) {
		if ('a' == ch) {
			++aCnt;
		}
		else if ('e' == ch) {
			++eCnt;
		}
		else if ('i' == ch) {
			++iCnt;
		}
		else if ('o' == ch) {
			++oCnt;
		}
		else if ('u' == ch) {
			++uCnt;
		}
		cout << "a" << aCnt << "\t" << "e" << eCnt << "\t" << "i" << iCnt << "\t" << "o" << oCnt << "\t" << "u" << uCnt << endl;
	}
	
	return 0;
}