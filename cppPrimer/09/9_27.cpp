#include <forward_list>
#include <iostream>

using namespace std;

int
main(int argc, char const *argv[])
{
	forward_list<int> fList{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	// auto pre = fList.cbefore_begin();
	// auto curr = fList.cbegin();

	// while (curr != fList.end()) {
	// 	if (!(*curr % 2)) {
	// 		pre = curr;
	// 		++curr;
	// 	}
	// 	else {
	// 		curr = fList.erase_after(pre);
	// 	}
	// }

	for (auto pre = fList.cbefore_begin(), curr = fList.cbegin(); curr != fList.cend();) {
		if (!(*curr % 2)) {
			pre = curr;
			++curr;
		}
		else {
			curr = fList.erase_after(pre);
		}
	}

	for (auto i : fList) {
		cout << i << endl;
	}

	return 0;
}