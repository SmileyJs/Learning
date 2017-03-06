#include <iostream>
#include <vector>	

using namespace std;

vector<int> *
buildCon()
{
	vector<int> *vec = new vector<int>();
	// vec.reserve(20);

	return vec;
}

void
getData(vector<int> *p)
{
	cout << "getData--Please input some integer: " << endl;

	int i;
	while (cin >> i) {
		p->push_back(i);
	}
}

void
printData(vector<int> *p)
{
	cout << "printData" << endl;

	for (auto i : *p) {
		cout << i << endl;
	}
}

int
main(int argc, char const *argv[])
{
	vector<int> *p_vec = buildCon();
	
	getData(p_vec);

	printData(p_vec);

	delete p_vec;

	return 0;
}