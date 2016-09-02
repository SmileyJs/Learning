#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int
main(int argc, char const *argv[])
{
	char ch;
	int aCnt = 0;
	int eCnt = 0;
	int iCnt = 0;
	int oCnt = 0;
	int uCnt = 0;

	while (cin >> ch) {
		switch (ch) {
			case 'a' : ;
			case 'A' : 
				++aCnt;
				break;
			case 'e' : ;
			case 'E' : 
				++eCnt;
				break;
			case 'i' : ;
			case 'I' :
				++iCnt;
				break;
			case 'o' : ;
			case 'O' :
				++oCnt;
				break;
			case 'u' : ;
			case 'U' :
				++uCnt;
				break;
			default :
				break;
		}
	}

	cout << "aA" << aCnt << "\t" << "eE" << eCnt << "\t" << "iI" << iCnt << "\t" << "oO" << oCnt << "\t" << "uU" << uCnt << endl;
	return 0;
}