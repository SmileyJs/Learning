#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int
main(int argc, char const *argv[])
{
	map<string, vector<int>> imap;

	imap.insert({"11", {1, 2}});

	map<string, vector<int>>::iterator relt = imap.find("11"); 

	return 0;
}