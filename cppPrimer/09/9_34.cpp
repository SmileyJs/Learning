#include <iostream>
#include <vector>

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<int> vi{0,1, 2, 3, 4, 5};

	auto iter = vi.begin();

	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);
			++ iter;
		}
		++ iter;
	}

	for (auto i : vi) {
		cout << i << endl;
	}

	return 0;
}