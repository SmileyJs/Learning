#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	static int arrayPairSum(vector<int>& v) {
		sort(v.begin(), v.end());

		int ret = 0;

		for (auto i = 0; i != v.size(); i += 2) {
			ret += std::min(v[i], v[i + 1]);
		}

		return ret;
	}
};

int
main(int argc, char const *argv[])
{
	vector<int> v{1, 3, 6, 3, 2, 5, 8, 9};

	cout << Solution::arrayPairSum(v) << endl;

	for (auto i : v) {
		cout << i << endl;
	}

	return 0;
}