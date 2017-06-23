#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	static string reserve(string s) {
		size_t beg = 0;
		for (size_t i = 0; i <= s.length(); ++i) {
			if (isspace(s[i]) || i == s.length()) {
				reverse(&s[beg], &s[i]);
				beg = i + 1;
			}
		}

		return s;
	}	
};

int
main(int argc, char const *argv[])
{
	string s1 = "let's take LeetCode contest";
	string s2 = "code";

	cout << Solution::reserve(s1) << endl;

	return 0;
}