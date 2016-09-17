#include <iostream>
#include <string>


using namespace std;

int
main(int argc, char const *argv[])
{
	string str_word = "";
	string str_preWord = "";
	string str_repeatWord = "";
	int repeatNum = 0;
	int maxRepeatNum = 0;

	while (cin >> str_word) {

		cout << "input word is " << str_word << endl;
		if (str_word == str_preWord) {
			++repeatNum;
		}
		else {
			repeatNum = 1;
			str_preWord = str_word;
		}

		if (repeatNum > maxRepeatNum) {
			str_repeatWord = str_preWord;
			maxRepeatNum = repeatNum;
		}
	}

	if (1 >= maxRepeatNum) {
		cout << "There is no repeat word in the string!" << endl;
	}
	else {
		cout << "The word " << str_repeatWord << " appears " << maxRepeatNum << " times!" << endl;
	}

	return 0;
}