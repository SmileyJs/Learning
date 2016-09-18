#include <iostream>
#include <string>

using namespace std;

int
main(int argc, char const *argv[])
{
	string word = "", preWord = "";

	while (cin >> word) {
		if (!isupper(word[0])) {
			preWord = "";
			continue;
		}

		if (word == preWord) {
			break;
		}
		else {
			preWord = word;
		}
	}

	if (cin.eof()) {
		cout << "No same word" << endl;
	}
	else {
		cout << "The same word is " << word << endl;
	}

	return 0;
}