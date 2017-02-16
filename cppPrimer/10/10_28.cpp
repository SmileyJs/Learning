#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<int> vec;
	for (int i = 0; i != 10; ++i) {
		vec.push_back(i);
	}

	list<int> back_lst;
	list<int> front_lst;
	list<int> lst;

	copy(vec.begin(), vec.end(), back_inserter(back_lst));
	copy(vec.begin(), vec.end(), front_inserter(front_lst));
	copy(vec.begin(), vec.end(), inserter(lst, lst.begin()));

	cout << "back_inserter:" << endl;
	for (auto i : back_lst) {
		cout << i << endl;
	}

	cout << "front_inserter: " << endl;
	for (auto i : front_lst) {
		cout << i << endl;
	}

	cout << "inserter:" << endl;
	for (auto i : lst) {
		cout << i << endl;
	}

	return 0;
}