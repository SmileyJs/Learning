#include <iostream>
#include <memory>
#include <vector>

using namespace std;

shared_ptr<vector<int>>
buildCon()
{
	shared_ptr<vector<int>> p = make_shared<vector<int>>();

	return p;
}

void
getData(shared_ptr<vector<int>> p)
{
	cout << "getData: please input the integer:" << endl;
	int i;
	while (cin >> i) {
		(*p).push_back(i);
	}
}

void
printData(shared_ptr<vector<int>> p)
{
	for (auto i : *p) {
		cout << i << endl;
	}
}

int
main(int argc, char const *argv[])
{
	shared_ptr<vector<int>> p = buildCon();

	getData(p);

	printData(p);

	return 0;
}