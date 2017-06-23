#include <iostream>
#include <vector>

using namespace std;

void generate(vector<vector<int>>& v, int rows)
{
	

}

int
main(int argc, char const *argv[])
{
	int i;
	cin >> i;

	vector<vector<int>> v;
	generate(v, i);

	for (auto i = 0; i != v.size(); ++i) {
		for (auto j : v[i]) {
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}