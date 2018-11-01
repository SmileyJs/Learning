#include <iostream>
#include <vector>
#include <set>

using namespace std;


vector<string>
findWords(vector<string>& words)
{
	set<char> top = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
	set<char> mid = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
	set<char> bottom = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

	vector<set<char>> rows = {top, mid, bottom};

	vector<string> ret;
	for (auto word : words) {

		int line = 0;
		for (; line < 3; ++line) {
			cout << line << static_cast<unsigned char>(tolower(word[0])) << endl;
			if (rows[line].count(tolower(word[0])) != 0) break;
		}

		bool result = true;
		for (auto c : word) {
			cout << c << endl;	
			if (rows[line].count(tolower(c)) == 0)	 {
				result = false;
				break;
			}
		}

		if (result)
			ret.push_back(word);
	}

	return ret;
}

int
main(int argc, char const *argv[])
{
	vector<string> words{"Hello", "Alaska", "Dad", "Pease"};

	vector<string> ret = findWords(words);

	for (auto s : ret) {
		cout << s << endl;
	}

	return 0;
}