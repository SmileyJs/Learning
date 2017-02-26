#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int
main(int argc, char const *argv[])
{

	// 11_9
	map<string, list<int>> imap;

	// 11_10
	map<vector<int>::iterator, int> vecmap;
	map<list<int>::iterator, int> listmap;

	vector<int> v1;
	vecmap.insert(pair<vector<int>::iterator, int>(v1.begin(), 0));

	list<int> v2;
	listmap.insert(pair<list<int>::iterator, int>(v2.begin(), 0));

	return 0;
}