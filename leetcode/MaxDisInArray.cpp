#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int distance(vector<vector<int>>& arrays)
{
	int l = arrays[0].front(), r = arrays[0].back(), ans = 0;

	for (int i = 1; i < arrays.size(); ++i) {
		ans = max(ans, max(abs(arrays[i].front() - r), abs(arrays[i].back() - l)));
		l = min(l, arrays[i].front());
		r = max(r, arrays[i].back());
	}

	return ans;
}

int
main(int argc, char const *argv[])
{
	vector<int> a{1, 2, 3, 4};
	vector<int> b{2, 3, 4};
	vector<int> c{5, 6, 7, 8};

	vector<vector<int>> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);

	cout << distance(v) << endl;

	return 0;
}