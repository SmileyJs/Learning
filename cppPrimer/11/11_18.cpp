#include <iostream>
#include <algorithm>
#include <map>
#include <cctype>

using namespace std;

int
main(int argc, char const *argv[])
{
	map<string, size_t> map_count;

	string word;

	while (cin >> word) {
		for (auto &c : word) {
			c = tolower(c);
		}

		++map_count[word];
	}

	map<string, size_t>::const_iterator s = map_count.cbegin();

	while (map_count.end() != s) {
		cout << s->first << " appears " << s->second << " times." << endl;
		++s;
	}

	return 0;
}