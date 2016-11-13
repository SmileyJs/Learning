#include "chapter6.h"

char &getChar(string &str, string::size_type i)
{
	return str[i];
}

const string &shortString(const string &str1, const string &str2)
{
	return str1.size() > str2.size() ? str1 : str2;
}

vector<string> process(const string &s1, const string &s2)
{
	if (s1.empty() || s2.empty()) {
		return {};
	}
	else if (s1 == s2) {
		return {"process", "equal"};
	}
	else {
		return {"process", s1, s2};
	}
}

int
main(int argc, char const *argv[])
{
	string s = "a value";
	cout << s << endl;
	getChar(s, 0) = 'A';
	cout <<s << endl;

	string s2 = "a long string";

	cout << shortString(s, s2) << endl;

	for (auto i : process(argv[1], argv[2])) {
		cout << i << endl;
	} 

	return 0;
}