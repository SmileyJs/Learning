#include <iostream>
#include <vector>

using namespace std;

void
insertVectorInt(vector<int> &v1, int value)
{
	auto iter = v1.begin();
	auto cursor = v1.size()/2;
	auto mid = v1.begin() + cursor;

	while (iter != mid) {
		if (*iter == value) {
			iter = v1.insert(iter, *iter * 2);
			++iter;
			++cursor;
			mid = v1.begin() + cursor;
		}
		++iter;
	}

}

void
print(const vector<int> &v1) 
{
	for (auto i = v1.begin(); i != v1.end(); ++i) {
		cout << *i << endl;
	}
}

int
main(int argc, char const *argv[])
{
	vector<int> v1{1, 2, 1, 3, 1, 7};
	
	insertVectorInt(v1, 1);
	print(v1);

	return 0;
}