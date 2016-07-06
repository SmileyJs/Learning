#include <iostream>
#include <vector>

using namespace std;

int
main()
{
	vector<int> ivec; 
//	vector<string> svec = ivec; 
	vector<string> svec(10, "null");
/**
	int n;
	string str;

	while (cin >> str) {
		svec.push_back(str);
	}

	for (int i = 0; i < svec.size(); ++i) {
		cout << svec[i] << endl;
	}
 */
/**
	vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int &i : v) {
		i *= i;
	}

	for (int i : v) {
		cout << i << endl;
	}
 */

	vector<unsigned> grade (11, 0);
	unsigned score  = 0;

	while (cin >> score) {
		if (score <= 100) {
			++grade[score/10];
		}
	}

	for (unsigned i : grade) {
		cout << i << endl; 
	}

//	for (unsigned i = 0; i < grade.size(); i++) {
//		cout << "grade[" << i << "] = " << grade[i] << endl; 
//	}

	return 0;
}
