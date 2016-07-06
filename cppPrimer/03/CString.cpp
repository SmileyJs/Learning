#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int
main(void)
{
	const char *a1 = "hello";
	const char *a2 = "world!";

	const size_t size = strlen(a1) + strlen(" ") + strlen(a2) + 1;

	char a3[size];
	strcpy(a3, a1);
	strcat(a3, " ");
	strcat(a3, a2);

	cout << a3 << endl;
	

/**
//	const char ca[] = {'h', 'e', 'l', 'l', 'o', '\0'};

	const char *ca = "helloworld\0";
	const char *cp = ca;

	while (*cp) {
		cout << *cp << endl;
		++cp;
	}

	string str1 = "hello";
	string str2 = "helloworld!";

//	char c1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
//	char c2[] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!'};

	char *c1 = "hello\0";
	char *c2 = "hello world\0";

	if (str1 == str2) {
		cout << "str1 is equal to str2!" << endl;
	}
	else if (str1 > str2) {
		cout << "str1 is larger than str2!" << endl;
	}
	else {
		cout << "str1 is small than str2!" << endl;
	}

	int value = strcmp(c1, c2);

	if (0 == value) {
		cout << "c1 is equal to c2!" << endl;
	}
	else if (0 > value) {
		cout << "c1 is small than c2!" << endl;
	}
	else {
		cout << "c1 is larger than c2!" << endl;
	}
 */

	return 0;
}
