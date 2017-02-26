#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

int
main(int argc, char const *argv[])
{
	string word;

	//set
	set<string> iset;

	// vector
	vector<string> ivec;

	while (cin >> word) {
		// iset.insert(word);
		if (ivec.end() == find(ivec.cbegin(), ivec.cend(), word)) {
			ivec.push_back(word);
		}
	}

	for (auto i : ivec) {
		cout << i << endl;
	}

	return 0;
}