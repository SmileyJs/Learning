#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int
main(int argc, char const *argv[])
{
	map<int, string> imap;

	imap.insert({1, "Bbbb"});

	for (auto i : imap) {
		cout << i.first << " " << i.second << endl;
	}

	map<int, string>::iterator iter = imap.begin();
	iter->second = "Aaaa";

	for (auto i : imap) {
		cout << i.first << " " << i.second << endl;
	}

	return 0;
}