#include <iostream>
#include <string>

using namespace std;

const string& strReplace(string &s, const string &oldStr, const string &newStr)
{
	for (auto i = s.begin(); distance(i, s.end()) >= distance(oldStr.begin(), oldStr.end());) {
		string tmp(i, i + oldStr.size());
		if (oldStr == tmp) {
			i = s.erase(i, i + oldStr.size());
			i = s.insert(i, newStr.begin(), newStr.end());
			advance(i, newStr.size());
		}
		else {
			++i;
		}
	}

	return s;
}

int
main(int argc, char const *argv[])
{
	string s1, s2;

	s1.assign("123tho=tho456");
	cout << strReplace(s1, "tho", "though") << endl;

	s2.assign("123thro=thro456");
	cout << strReplace(s2, "thro", "through") << endl;

	return 0;
}