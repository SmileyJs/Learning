#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class IsEqual
{
	string::size_type size;
public:
	IsEqual(string::size_type u) : size(u) {}
	
	bool operator()(const string& s) {
		return s.size() == size ? true : false;
	}
};

int
main(int argc, char const *argv[])
{
	vector<string> v{"aa", "bb", "c", "dd", "e", "ff", "g"};
	vector<string> words;

	ifstream ifs("./words.txt");

	if (!ifs)
		return -1;

	string str;
	while (ifs >> str) {
		words.push_back(str);
	}

	for (int i = 0; i < 10; ++i) {
		int cnt = count_if(words.begin(), words.end(), IsEqual(i + 1));
		cout << "length: " << i + 1 << "'number " << cnt << endl;
	}

	return 0;
}