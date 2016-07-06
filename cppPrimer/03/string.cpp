#include <iostream>

using namespace std;

int main(void)
{
	string s1, s2;

//	cin >> s1 >> s2;
//	cout << s1 << s2 << endl;

//	while (cin >> s1) {
//		cout << s1 << endl;
//		cout.flush();
//	}

	while (getline(cin, s1)) {
		if ((!s1.empty()) && s1.size() < 10) {
			cout << s1 << endl;
		}
	}

	return 0;
}
