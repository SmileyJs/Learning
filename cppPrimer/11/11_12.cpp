#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<pair<string, int>> ivec;

	string word;
	int num;

	while (cin >> word >> num) {
		// constructor
		// ivec.push_back({word, num});
		
		// make pair
		// ivec.push_back(make_pair(word, num));

		// emplace 
		ivec.emplace_back(word, num);
	}

	for (auto i : ivec) {
		cout << i.first << " " << i.second << endl;
	}

	return 0;
}