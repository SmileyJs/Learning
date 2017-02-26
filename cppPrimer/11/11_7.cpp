#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int
main(int argc, char const *argv[])
{
	map<string, vector<string>> family = {
		{"Wang", {"xiaoming", "haha"}},
		{"Zhang", {"xiaoming"}}
	};

	string firstName, lastName;

	// the () after lambda used to call lambda, otherwise it will not execute.
	// whiel(lambda()){}

	while ([&]() -> bool {
		cout << "Please input the first name: " << endl;
		return cin >> firstName && firstName != "q";
	}())
	{
		while ([&]() -> bool {
			cout << "Please input the last name: " << endl;
			return cin >> lastName && lastName != "q";
		}()) 
		{
			family[firstName].push_back(lastName);
		}
	}		

	for (auto i : family) {
		cout << "family: " << i.first << endl;
		for (auto s : i.second) {
			cout << "name: " << s << endl;
		}
	}

	return 0;
}