#include <iostream>
#include <string>

using namespace std;

int
main(int argc, char const *argv[])
{
	string s("ab2c3d7R4E6");

	string letter("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string number("0123456789");

	string::size_type pos = 0;

	while ((pos = s.find_first_of(number, pos)) != string::npos) {
		cout << "find number " << s[pos] << " at index " << pos << endl;
		++pos;
	}

	pos = 0;
	while ((pos = s.find_first_of(letter, pos)) != string::npos) {
		cout << "find letter " << s[pos] << " at index " << pos << endl;
		++pos;
	}

	return 0;
}