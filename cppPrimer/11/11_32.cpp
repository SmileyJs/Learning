#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

int
main(int argc, char const *argv[])
{
	multimap<string, string> imap;
	map<string, multiset<string>> order_map;

	imap.insert({"John", "CCCCCC"});
	imap.insert({"John", "BBBBBB"});
	imap.insert({"John", "CCCCCC"});
	imap.insert({"John", "AAAAAA"});
	imap.insert({"Lee", "AAAAAA"});
	imap.insert({"Lee", "CCCCCC"});
	imap.insert({"Lee", "BBBBBB"});
	imap.insert({"Anna", "AAAAAA"});
	imap.insert({"Anna", "BBBBBB"});

	for (auto i : imap) {
		order_map[i.first].insert(i.second);
	}

	for (auto i : order_map) {
		cout << i.first << ": " << endl;
		for (auto j : i.second) {
			cout << j << endl;
		}
	}


	return 0;
}