#include "Blob.h"

int
main(int argc, char const *argv[])
{
	Blob<int> a{1, 2, 3, 4, 5};

	for (auto i = a.begin(); i != a.end(); ++i) {
		cout << i.deref() << endl;
	}

	cout << a.size() << endl;

	BlobPtr<int> p(a, 3);

	cout << *p << endl;

	cout << a.front() << endl;
	cout << a.back() << endl;

	a.push_back(6);

	for (auto i = a.begin(); i != a.end(); ++i) {
		cout << i.deref() << endl;
	}

	a.pop_back();

	for (auto i = a.begin(); i != a.end(); ++i) {
		cout << i.deref() << endl;
	}

	BlobPtr<int> b(a);

	cout << a.size() << " " << *a.begin() << " " << *(a.end() - 1) << endl;

	

	// 16_24
	cout << "16_24" << endl;
	vector<int> v1{1, 2, 3, 4, 5};

	Blob<int> v2(a.begin(), a.end());
	for (auto i : v2) {
		cout << i << endl;
	}

	return 0;
}