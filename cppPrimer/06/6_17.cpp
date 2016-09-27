#include "chapter6.h"

int
main(int argc, char const *argv[])
{
	string str = "This is a string";
	int count = 0; 

	cout << "Please input a string" << endl;

	while (getline(cin, str) && str != "") {
		
		cout << "Char 'c' appears first time at " << findChar(str, 'c', count) << endl;
		cout << "total " << count << "times" << endl;
		
		if (bHasCapitalLetter(str)) {
			cout << "There is captial letrer in " << str << endl;
			changeLowerLetter(str);
			cout << "After tolower, the string is " << str << endl;
		}
		else {
			cout << "There is no captial letter in string " << str << endl;
		}
	}

	return 0;
}

bool
bHasCapitalLetter(const string &str)
{
	for (char c : str) {
		if (isupper(c))
			return true;
	}
	return false;
}

void
changeLowerLetter(string &str)
{
	for (char &c : str) {
		if (isupper(c)) 
			c = tolower(c);
	}
}

string::size_type
findChar(const string &str, char c, int &count)
{
	count = 0;
	string::size_type rsp = str.size();
	for (string::size_type i = 0; i != str.size(); ++i) {
		if (str[i] == c) {
			++count;
			if (rsp == str.size()) {
				rsp = i;
			}
		}
	}

	return rsp;
}