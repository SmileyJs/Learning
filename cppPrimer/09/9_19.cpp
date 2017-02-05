#include <list>
#include <iostream>

using namespace std;

int
main(int argc, char const *argv[])
{
	list<string> l1;
	string word;

	while (cin >> word) {
		l1.push_back(word);
	}

	for (auto i = l1.begin(); i != l1.end(); ++i) {
		cout << *i << endl;
	}

	return 0;
}