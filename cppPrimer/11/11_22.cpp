#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int
main(int argc, char const *argv[])
{
	map<string, vector<int>> imap;

	pair<map<string, vector<int>>::iterator , bool> iter = imap.insert({"111", {1, 2, 3}});

	for (auto s : imap) {
		cout << s.first << endl;
		for (auto i : s.second) {
			cout << i << endl;
		}
		cout << endl;
	}

	return 0;
}