#include <deque>
#include <iostream>

using namespace std;

int
main(int argc, char const *argv[])
{
	deque<string> d1;
	string word;

	while (cin >> word) {
		d1.push_back(word);
	}

	for (auto i = d1.begin(); i != d1.end(); ++i) {
		cout << *i << endl;
	}

	return 0;
}