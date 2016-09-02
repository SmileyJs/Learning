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
	int spaceCnt = 0;
	int tabCnt = 0;
	int nCnt = 0;

	while (cin >> std::noskipws >> ch) {
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
			case ' ' :
				++spaceCnt;
				break;
			case '\t' :
				++tabCnt;
				break;
			case '\n' :
				++nCnt;
				break;
			default :
				break;
		}
	}

	cout << "aA" << aCnt << "\t" << "eE" << eCnt << "\t" << "iI" << iCnt << "\t" << "oO" << oCnt << "\t"
			<< "uU" << uCnt << " \t" << "space" << spaceCnt << "\t" << "tab" << tabCnt << "\t" << "newLine" << nCnt << endl;
	return 0;
}