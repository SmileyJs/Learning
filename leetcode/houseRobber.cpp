#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> &nums)
{
 	// int n = nums.size();

 	// if (0 == n) return 0;
 	// if (1 == n) return nums[0];
 	
 	// vector<int> f(n, 0);
 	// f[0] = nums[0];
 	// f[1] = max(f[0], nums[1]);

 	// for (int i = 2; i != n; ++i) {
 	// 	f[i] = max(f[i-2] + nums[i], f[i-1]);
 	// }

 	// return f[n-1];

 	int ret1 = 0, ret2 = 0;

 	for (int i = 0; i != nums.size(); ++i) {
 		if (i % 2) {
 			ret1 = max(ret1 + nums[i], ret2);
 		}
 		else {
 			ret2 = max(ret2 + nums[i], ret1);
 		}
 	}

 	return max(ret1, ret2);
}

int
main(int argc, char const *argv[])
{
	vector<int> v{2, 5, 17, 3, 9, 28, 19, 29, 5, 7, 31};

	cout << rob(v) << endl;

	return 0;
}