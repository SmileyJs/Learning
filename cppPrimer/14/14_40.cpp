#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

class CompareSize
{
public:
	bool operator() (const string& s1, const string& s2) {
		return s1.size() < s2.size();
	}
};

class FindSize
{
	size_t size;
public:
	bool operator() (const string& s) {
		return s.size() > size;
	}

	FindSize(size_t s) : size(s) {}
};

class Printer
{
public:
	void operator() (const string& s)
	{
		cout << s << " ";
	}
};

void elimDups(vector<string>& v)
{
	sort(v.begin(), v.end());

	auto end_unique = unique(v.begin(), v.end());
	v.erase(end_unique, v.end());
}

void biggies(vector<string>& v, size_t sz)
{
	elimDups(v);

	stable_sort(v.begin(), v.end(), CompareSize());

	auto i = find_if(v.begin(), v.end(), FindSize(sz));

	auto count = v.end() - i;

	cout << "There are " <<  count <<  " words of length " << sz << " or longer." << endl;

	for_each(i, v.end(), Printer());

	cout << endl;
}

int
main(int argc, char const *argv[])
{
	ifstream ifs("./words.txt");

	if (!ifs)
		return -1;

	vector<string> words;
	string str;

	while (ifs >> str) {
		words.push_back(str);
	}

	biggies(words, 5);

	return 0;
}