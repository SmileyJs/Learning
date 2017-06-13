#include <iostream>
#include "BlobNew.h"
#include <vector>

using namespace std;

int
main(int argc, char const *argv[])
{
	vector<int> v1{1, 2, 3, 4, 5};
	Blob<int> v2(v1.begin(), v1.end()); 

	for (auto i : v2) {
		cout << i << endl;
	}

	return 0;
}