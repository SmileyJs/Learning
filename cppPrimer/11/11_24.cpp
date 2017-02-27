#include <iostream>
#include <map>
#include <vector>

using namespace std;

int
main(int argc, char const *argv[])
{	
	map<int, int> m;
	m[0] = 1;

	for (auto i : m) {
		cout << i.first << " " << i.second << endl;
	}

	vector<int> v;
	// v[0] = 1;
	// illegal, meaningless  v.size is 0.

	for (auto i : v) {
		cout << i << endl;
	}

	map<string, int> imap{{"111", 1}, {"222", 2}};

	map<string, int>::key_type kt = "333";

	map<string, int>::mapped_type mt = imap[kt];

	cout << mt << endl;

	return 0;
}