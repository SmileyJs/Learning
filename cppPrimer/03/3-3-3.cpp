#include <vector>
#include <iostream>

using namespace std;

int
main()
{	
	vector<int> num;
	int n = 0;

	while (cin >> n) {
		num.push_back(n);
	}

	if (num.empty()) {
		printf("Please input some integer!");
		return -1;
	} else if (1 == num.size()) {
		printf("There's no adjacent elements!");
		return -2;
	}

	for (decltype(num.size()) i = 0; i < num.size() - 1; ++i) {
		cout << "Sum of adjacent " << num[i] << " and " << num[i+1] 
			<< " is " << num[i] + num[i+1] << endl;
	}

	decltype(num.size()) size = num.size();

	if (size % 2 != 0) {
		size = size / 2 + 1;
	} else {
		size /= 2;
	}

	for (decltype(num.size()) i = 0; i < size; ++i) {
		cout << "Sum of opposite num " << num[i] << " and " << num[num.size() - i - 1] 
			<< " is " << num[i] + num[num.size() - i - 1] << endl; 
	}

/** 3-17
	vector<string> s;
	string str;

	while (cin >> str) {
		if (!str.empty()) {
			s.push_back(str);
		}
	}

	for (string &ss : s) {
		for (char &sss : ss) {
			sss = toupper(sss);
		}
	}

	for (string ss : s) {
		cout << ss << endl;
	}
*/

/** 3.16
	vector<int> v1;

	cout << "v1" << v1.size() << endl;

	vector<int> v2(10);

	for (int i : v2) {
		cout << "v2" << i << endl;
	}

	vector<int> v3(10, 42);

	for (int i : v3) {
		cout << "v3" << i << endl;
	}

	vector<int> v4{10};

	for (int i : v4) {
		cout << "v4" << i << endl;
	}

	vector<int> v5{10, 42};

	for (int i : v5) {
		cout << "v5" << i << endl;
	}

	vector<string> v6{10};

	for (string i : v6) {
		cout << "v6" << i << endl;
	}

	vector<string> v7(10, "hi");

	for (string i : v7) {
		cout << "v7" << i << endl;
	}
 */
	return 0;
}
