#include <iostream>
#include <vector>

using namespace std;

int
main()
{
/** 3-26 */

	vector<int> num;
	for (int i = 0; i < 10; ++i) {
		num.push_back(i);
	}

	for (int i : num) {
		cout << i << endl;
	}

	int n;
	cin >> n;

	vector<int>::const_iterator beg = num.cbegin();
	vector<int>::const_iterator end = num.cend();

	auto mid = beg + (end - beg) / 2;

	while (mid != end && n != *mid) {
		if (n > *mid) {
			beg = mid + 1;
		} else {
			end = mid;
		}

		cout << "progress 1...... " << *mid << endl;
		mid = beg + (end - beg) / 2;
		cout << "progress 2...... " << *mid << endl;
	}

	cout << "The result is " << *mid << endl;
	

	
	/**
	vector<int> grade(11, 0);

	unsigned score;

	while (cin >> score) {
		if (score <= 100) {
			++*(grade.begin() + score / 10);
		} else {
			printf("score inputed is invalid!\n");
		}
	}

	for (int i : grade) {
		cout  << i << endl;
	}
*/
/** 3-24
	vector<int> num;
	int n;

	while(cin >> n) {
		num.push_back(n);
	}

	for (int n : num) {
		cout << n << endl;
	}

	if (num.empty() || 1 == num.size()) {
		printf("num's number is invalid");
		return -1;
	}

	for (vector<int>::iterator i = num.begin(); i != num.end() - 1; ++i) {
		cout << "Sum of adjacent number is " << *i + *(i+1) << endl;
	}

	auto size = num.end() - num.begin();

	if (0 == (num.end() - num.begin()) % 2) {
		size = (num.end() - num.begin()) / 2;
	} else {
		size = ((num.end() - num.begin()) / 2) + 1;
	}

	for (auto i = 0; i != size; ++i) {
		cout << "Sum of opposite number is " << *(num.cbegin() + i) + *(num.cend() - i - 1) << endl;
	}
 */
/** 3-23 
	vector<int> num;

	for (int i = 0; i < 10; ++i) {
		num.push_back(i);
	}

	for (vector<int>::iterator i = num.begin(); i != num.cend(); ++i) {
		*i *= *i;
	}

	for (int value : num) {
		cout << value << endl;
	}
*/
/** 3-22
	vector<string> text;
	string str("");

	while (getline(cin, str)) {
		text.push_back(str);
	}

	for (string s : text) {
		cout << s << endl;
	}

	for (auto i = text.begin(); i != text.end() && !(*i).empty(); ++i) {
		for (char &s : *i) {
			s = toupper(s);
		}
		cout << "The out put is " << *i  << endl;
	}
*/
/**  3.21
	vector<int> v1;

	if (v1.cbegin() != v1.cend()) {
		for (int x : v1) {
			cout << "v1" << x << endl;
		}
	} else {
		printf("v1 has no members!\n");
	}

	vector<int> v2(10);

	for (vector<int>::const_iterator i = v2.cbegin(); i != v2.cend(); ++i) {
		cout << "v2" << *i  << endl;
	}
	
	vector<int> v3(10, 42);

	for (auto i = v3.cbegin(); i != v3.cend(); ++i) {
		cout << "v3" << *i << endl;
	}

	vector<int> v4{10};

	for (auto i = v4.cbegin(); i != v4.cend(); ++i) {
		cout << "v4" << *i << endl;
	}

	vector<int> v5{10, 42};

	for (auto i = v5.cbegin(); i != v5.cend(); ++i) {
		cout << "v5" << *i << endl;
	}

	vector<string> v6{10};

	for (auto i = v6.cbegin(); i != v6.cend(); ++i) {
		cout << "v6" << *i << endl;
	}

	vector<string> v7{10, "hi"};

	for (auto i = v7.cbegin(); i != v7.end(); ++i) {
		cout << "v7" << *i << endl;
	}
 */
	return 0;
}
