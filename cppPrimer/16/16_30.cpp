#include "Blob_SharedPtr.h"

int
main(int argc, char const *argv[])
{
	Blob<string> v1{"aa", "bb", "cc", "dd", "ee"};

	cout << v1.front() << endl;
	cout << v1.back() << endl;

	cout << "count: " << v1.count() << "empty: " << v1.empty() << "size: " << v1.size() << endl;

	cout << v1[2] << endl;

	v1.push_back("ff");

	cout << v1.back() << endl;

	return 0;
}