#include <iostream>
#include <sstream>

using namespace std;

istream&
read(istream &is) {
	string str;

	while (is >> str) {
		cout << str << endl;
	} 

	str.clear();

	return is;
}

int
main(int argc, char const *argv[])
{
	istringstream s("Jsssssss..............");

	if (s) {
		read(s);
	}

	return 0;
}