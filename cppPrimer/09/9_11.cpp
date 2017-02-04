#include <vector>

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<int> v1(10, 1);

	vector<int> v2{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	vector<int> v3(v2);

	vector<int> v4;

	vector<int> v5(10);

	vector<int> v6(v2.begin(), v2.end());

	return 0;
}