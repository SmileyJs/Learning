#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class NumArray{
	vector<int> data;
public:
	explicit NumArray(vector<int> v) : data(v.size() + 1, 0) {
		partial_sum(v.begin(), v.end(), data.begin() + 1);
	}

	int sumRange(int i, int j) {
		return data.at(j+1) - data.at(i);
	}
};

int
main(int argc, char const *argv[])
{
	vector<int> nums{0, 1, 2, 3, 4, 5};

	NumArray* obj = new NumArray(nums);
	
	int param1 = obj->sumRange(1, 2);
	cout << param1 << endl;

	cout << obj->sumRange(2, 5) << endl;

	return 0;
}