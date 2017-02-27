#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int
main(int argc, char const *argv[])
{
	map<string, int> word_count;

	string word;

	while (cin >> word) {
		// ++word_count[word];

		// 11_20
		// pair<map<string, int>::iterator, bool> iter = word_count.insert({word, 1});

		// if (!iter.second) {
		// 	++iter.first->second;
		// }

		// 11-21
		++word_count.insert({word, 0}).first->second;
		// if not exist, return the inserted iterator end() and true.
		// if element has exist, return the same element's iterator and false?
	}

	for (auto s : word_count) {
		cout << s.first << " appears " << s.second << " times." << endl; 
	}

	return 0;
}