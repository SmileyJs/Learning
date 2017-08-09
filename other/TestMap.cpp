#include <iostream>
#include <map>
#include <string>

using namespace std;

int
main(int argc, char const *argv[])
{
	std::multimap<string, string> iMap;

	for (auto i : iMap) {
		cout << i.first << " " << i.second << endl;
	}

	iMap.insert(std::pair<string, string>("44", "haha"));
	iMap.insert(std::pair<string, string>("55", "haha"));
	iMap.insert(std::pair<string, string>("66", "haha"));
	iMap.insert(std::pair<string, string>("11", "haha"));
	iMap.insert(std::pair<string, string>("22", "haha"));
	iMap.insert(std::pair<string, string>("33", "haha"));
	iMap.insert(std::pair<string, string>("11", "haha"));

	for (auto i : iMap) {
		cout << i.first << " " << i.second << endl;
	}

	auto it = iMap.find("11");

	cout << it->first << " " << it->second << endl;

	it = iMap.erase(it);

	cout << it->first << " " << it->second << endl;	

	return 0;
}