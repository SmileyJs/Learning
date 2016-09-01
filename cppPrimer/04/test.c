// #include <iostream>
#include <string.h>

// using std::cout;
// using std::cin;
// using std::endl;
// using std::string;

// int
// main(void)
// {
// 	// cout << "Please input some integer!" << endl;

// 	// int i;

// 	// while (cin >> i && i != 42) {
// 	// 	cout << "haha" << endl;
// 	// }

// 	string s, t = "a value";

// 	cout << s << t << endl;

// 	return 0;
// }

int main()
{
	char s[100]="1111+2222+3333+4444+5555+6666";
	char *p=(char *)malloc(100);
	p = strstr(s, "+");
	while (p != NULL)
	{	
		strcpy(p, p+1);	
		p = strstr(s, "+");
	}
	printf("%s\n", s);
}