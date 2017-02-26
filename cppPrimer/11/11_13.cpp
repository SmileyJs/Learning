#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Family
{
public:
	Family& add(const string &, const string &, const string &);
	void print();

private:
	map<string, vector<pair<string, string>>> data;
};

Family&
Family::add(const string &firstName, const string &lastName, const string &birthDay) {
	data[firstName].push_back({lastName, birthDay});
	return *this;
}

void 
Family::print() {
	for (auto i : data) {
		cout << "family: " << i.first << endl;
		for (auto s : i.second) {
			cout << "name: " << s.first << " birthday: " << s.second << endl;
		}
	}
};

int
main(int argc, char const *argv[])
{
	Family iFamily;
	iFamily.add("Wang", "js", "19901111").add("Wang", "haha", "20101111").
		add("Zhang", "xiaogong", "20100210").add("Li", "xiaoming", "19901101");

	string firstName, lastName, birthDay;
	cout << "Please input the first name, lastName and birthday: " << endl;

	while (cin >> firstName >> lastName >> birthDay)
	{
		iFamily.add(firstName, lastName, birthDay);
	}		

	iFamily.print();

	return 0;
}