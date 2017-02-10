#include <iostream>
#include <string>

using namespace std;

const string&
strReplace(string &s, const string &oldVal, const string &newVal)
{
	for (auto i = s.begin(); i + oldVal.size() - 1 != s.end();) {
		string s1(i, i + oldVal.size());
		if (oldVal == s1) {
			i = s.erase(i, i + oldVal.size());
			s.insert(i, newVal.begin(), newVal.end()-1);
			// i += newVal.size();
			cout << s << endl;
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
	string s1;
	s1.assign("wwwthowww");

	cout << strReplace(s1, "tho", "though") << endl;

	return 0;
}