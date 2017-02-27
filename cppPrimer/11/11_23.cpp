#include <iostream>
#include <map>
#include <string>

using namespace std;

int
main(int argc, char const *argv[])
{
	multimap<string, string> family;

	cout << "Please input your lastName and childName" << endl;

	string lastName, childName;

	while (cin >> lastName >> childName) {
		family.insert({lastName, childName});
	}

	for (auto i : family) {
		cout << i.first << " " << i.second << endl;
	}

	return 0;
}