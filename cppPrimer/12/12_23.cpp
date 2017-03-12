#include <new>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int
main(int argc, char const *argv[])
{
	const char *a = "abc", *b = "bcd";

	// cout << strlen(a) << " " << strlen(b) << endl; 3 3

	unsigned len = strlen(a) + strlen(b) + 1;

	char *rzt1 = new char[len]();

	strcat(rzt1, a);

	strcat(rzt1, b);

	puts(rzt1);

	delete [] rzt1;

	const string c = "cde", d = "def";

	unsigned len2 = c.size() + d.size() + 1;

	// cout << c.size() << " " << d.size() << endl; 3	3

	char *rzt2 = new char[len2]();

	strcat(rzt2, (c + d).c_str());

	cout << rzt2 << endl;

	delete [] rzt2;

	return 0;
}	