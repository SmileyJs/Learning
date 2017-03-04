#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int
main(int argc, char const *argv[])
{
	unordered_map<string, int> word_count;
	string word;

	while (cin >> word) {
		++word_count[word];
	}

	for (auto i : word_count) {
		cout << i.first << " appears " << i.second
			<< ((i.second > 1) ? " times." : " time.") << endl;
	}

	return 0;
}