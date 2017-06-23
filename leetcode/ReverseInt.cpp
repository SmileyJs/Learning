#include <iostream>
#include <limits>

using namespace std;

class Solution
{
public:
	static int reserve(int x) {
		long ret = 0;
		while (x) {
			ret = ret*10 + x%10;
			x /= 10;
		}

		return (ret < std::numeric_limits<int>::min() || ret > std::numeric_limits<int>::max()) ? 0 : ret;
	}
};

int
main(int argc, char const *argv[])
{
	cout << "limits: min, " << std::numeric_limits<int>::min() << " max, " << std::numeric_limits<int>::max() << endl;

	int a = 0;

	cout << "please input a integer: ";

	cin >> a;

	cout << Solution::reserve(a) << endl;

	return 0;
}