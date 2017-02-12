#include <iostream>
#include <string>

using namespace std;

int
main(int argc, char const *argv[])
{
	string s("ab2c3d7R4E6");

	string letter("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string number("0123456789");

	for (string::size_type pos = 0; (pos = s.find_first_not_of(letter, pos)) != string::npos; ++pos) {
		cout << "find not letter " << s[pos] << " at index " << pos << endl; 
	}

	for (string::size_type pos = 0; (pos = s.find_first_not_of(number, pos)) != string::npos; ++pos) {
		cout << "find not number " << s[pos] << " at index " << pos << endl; 
	}

	return 0;
}