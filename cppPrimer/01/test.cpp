#include <iostream>

using namespace std;

int main()
{
	int crtValue =0;
	int value = 0;

	if (cin >> crtValue) {
		int cnt = 1;
		while (cin >> value) {
			if (crtValue == value) {
				++ cnt;
			}
			else {
				cout << "The number " <<  crtValue << " appears " << cnt << " times!" << endl;
				crtValue = value;
				cnt = 1;
			}
		}
		cout << "The number " <<  crtValue << " appears " << cnt << " times!" << endl;
	}


}
