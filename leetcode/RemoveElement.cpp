#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	static size_t removeEle(vector<int> v, int t) 
	{
		size_t n = v.size();

		size_t i = 0;
		while (i != n) {
			if (v[i] == t) {
				v[i] = v[n - 1];
				--n;
			}
			else {
				++i;
			}
		} 

		return n;
	}
};

int
main(int argc, char const *argv[])
{
	vector<int> v = {0, 1, 2, 1, 4};

	cout << Solution::removeEle(v, 1) << endl;

	for (auto i : v) {
		cout << i << endl;
	}


	return 0;
}