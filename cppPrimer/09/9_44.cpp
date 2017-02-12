#include <iostream>
#include <string>

using namespace std;

const string &strReplace(string &s, const string &oldStr, const string &newStr)
{
	for (int i = 0; i < s.size() - oldStr.size(); ++i) {
		string tmp(s, i, oldStr.size());
		if (oldStr == tmp) {
			s.replace(i, oldStr.size(), newStr);
			i += newStr.size() -1;
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