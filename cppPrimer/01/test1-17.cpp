#include <iostream>

using namespace std;

int main()
{
	int crtValue = 0;
	int value = 0;

	if (cin >> crtValue) {
		int cnt = 1;

		while (cin >> value) {
			if (value == crtValue) {
				++ cnt;
			} 
			else {
				cout << "The number " << crtValue << " appears " << cnt << " times." << endl;
				cnt = 1;
				crtValue = value;
			}
		}

		cout << "The number " << crtValue << " appears " << cnt << " times." << endl;
	
	}

	return 0;
}
