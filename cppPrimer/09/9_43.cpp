#include <iostream>
#include <string>

using namespace std;

const string&
strReplace(string &s, const string &oldVal, const string &newVal)
{
	cout << s << endl;
 	for (auto i = s.begin(); i + oldVal.size() - 1 != s.end();) {
		string s1(i, i + oldVal.size());
		if (oldVal == s1) {
			i = s.erase(i, i + oldVal.size());
			i = s.insert(i, newVal.cbegin(), newVal.cend());
			i += newVal.size();
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