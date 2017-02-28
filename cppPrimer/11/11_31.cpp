#include <iostream>
#include <map>
#include <string>

using namespace std;

int
main(int argc, char const *argv[])
{
	multimap<string, string> imap;

	if (argc != 3) {
		cout << "argument error !" << endl;
		return -1;
	}

	string author = argv[1], work = argv[2];

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
		cout << i.first << " " << i.second << endl;
	}

	auto iter = imap.find(author);

	auto count = imap.count(author);

	while (count) {
		if (iter->second == work) {
			imap.erase(iter);
			break;
		}

		iter++;
		count--;
	}

	for (auto i : imap) {
		cout << i.first << " " << i.second << endl;
	} 

	return 0;
}