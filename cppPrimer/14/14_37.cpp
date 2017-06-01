#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TestEqual
{
	string s;
public:	
	TestEqual(const string& str) : s(str) {}

	bool operator()(const string& s1) {
		return s1 == s ? true : false;
	}
};

int
main(int argc, char const *argv[])
{
	vector<string> v{"1", "2", "3", "a", "a", "4", "a"};

	TestEqual a("a");

	replace_if(v.begin(),v.end(), a, "z");

	for (auto &i : v) {
		cout << i << endl;
	}

	return 0;
}