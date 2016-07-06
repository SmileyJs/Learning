#include <iostream>

using namespace std;

int main() 
{
	string str("");
	string s("hello world!");
/**	
 	while (getline(cin, s)) {
 		cout << "cin's string is " << s << endl;
 		str += s;
 	}

	cout << "The large string is " << str << endl;

	decltype(s.size()) punct_cnt = 0;
  
	for (auto c : str) {
		if (ispunct(c)) {
			punct_cnt++;
		}
	}

	cout << "The punct's number is " << punct_cnt << endl;	

	for (char &c : s) {
		c = toupper(c);
	}	
	
	for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index) {
		s[index] = toupper(s[index]);
	}
	
	cout << "The string was changed to " << s << endl;
 */

/**
	const string hexDigits = "0123456789ABCDEF";
	
	string result_string = "";

	decltype (hexDigits.size()) n = 0;

	cout << "Please input a number between 0~15!" << endl << "Separate by space and finished by Enter" << endl;

	while (cin >> n) {
		if (n < hexDigits.size()) {
//			result_string = result_string + hexDigits[n] + " ";
			result_string += hexDigits[n]; 
		}
	}

	cout << "The changed number is " << result_string << endl;
 */

/** 3-9
	cout << str[0] << endl;
 */

/** 3-8
	getline(cin, str);

	cout << "The string is " << str << endl;

	printf("Changing......\n");
	
	for (char &c : str) {
		c = 'X';
	}
	
	decltype(str.size()) index = 0;
	
	while (index != str.size()) {
		str[index] = 'X';
		++index;
	}

	cout << "The string after change is " << str << endl;

	for (index = 0; index < str.size(); ++index) {
		str[index] = 'Y';
	}

	cout << "The string after change is " << str << endl;
 */	
	string stringResult("");

/** 3-10 1
	while(getline(cin, str)) {
		for (char c : str) {
			if (!ispunct(c)) {
				cout << c;
			}
		}
		cout << endl;
	}
 */

/** 3-10 2

	while(getline(cin, str)) {
		cout << "The input string is " << str << endl;
		stringResult += str;
	}
	
	cout << "The stringResult is " << stringResult << endl; 

	for (char &c : stringResult) {
		if (ispunct(c)) {
			c = '\0';
		}
	}
 */
/** method 2
	decltype(stringResult.size()) index;

	for (index = 0; index < stringResult.size(); ++index) {
		if (ispunct(stringResult[index])) {
			stringResult[index] = '\0';
		}
	}
 */
	
	const string test = "hello!world?";

	for (const char &c : test) {
		if (ispunct(c)) {
			//c = '\0';
		}
	}

	cout << "The string after change is " << stringResult << endl;

	return  0;
}
