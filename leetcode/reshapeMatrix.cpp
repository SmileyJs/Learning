#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>
matrixReshape(vector<vector<int>>& nums, int r, int c)
{
	int rows = nums.size();
	int cols = nums[0].size();

	if (rows*cols != r*c) return nums;

	vector<vector<int>> ret(r, vector<int>(c, 0));

	for (int i = 0; i < r*c; ++i) {		
		ret[i/c][i%c] = nums[i/cols][i%cols];  
	}

	return ret;
}

int
main(int argc, char const *argv[])
{
	vector<int> a = {1, 2};
	vector<int> b = {3, 4};

	vector<vector<int>> nums = {a, b};

	auto ret = matrixReshape(nums, 1, 4);

	for (auto v : ret) {
		for (auto i : v) {
			cout << i;
		}
		cout << endl;
	}

	return 0;
}