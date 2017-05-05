#include <iostream>

using namespace std;

int
main(int argc, char const *argv[])
{
	int i = 0;

	// while (cin >> i) {
	// 	switch(i) {
	// 				default:
	// 		cout << "xx" << endl;
	// 		break;	
	// 	case 1:
	// 		cout << "a" << endl;
	// 		break;
	// 	case 2:
	// 		cout << "b" << endl;
	// 		break;

	// 	}
	// }

	int n = 'c';
	switch(n++){
	default : cout << "error" << endl;
		break;
	case 'a' :
	case 'b' :
	case 'A' :
	case 'B' :
		cout << "ab" << endl;
	case 'c' :
	case 'C' :
		cout << "c" << endl;
	case 'd' :
	case 'D' :
		cout << "d" << endl;
	}
	return 0;
}