#include <iostream>

using namespace std;


int
main(int argc, char const *argv[])
{
	char ch, preCh = '/0';
	int aCnt = 0;
	int eCnt = 0;
	int iCnt = 0;
	int oCnt = 0;
	int uCnt = 0;
	int spaceCnt = 0;
	int tabCnt = 0;
	int nCnt = 0;
	int ffCnt = 0;
	int fiCnt = 0;
	int flCnt = 0;

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
			case 'i' : 
				if ('f' == preCh) ++fiCnt;
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
			case 'f' :
				if ('f' == preCh) ++ffCnt;
				break;
			case 'l' :
				if ('f' == preCh) ++flCnt;
				break;
			default :
				break;
		}
		preCh = ch;
	}

	cout << "aA" << aCnt << "\t" << "eE" << eCnt << "\t" << "iI" << iCnt << "\t" << "oO" << oCnt << "\t"
			<< "uU" << uCnt << "\t" << "space" << spaceCnt << "\t" << "tab" << tabCnt << "\t" 
			<< "newLine" << nCnt << "\t" << "ff" << ffCnt << "\t" << "fi" << fiCnt << "\t" << "fl" << flCnt << endl;
	return 0;
}