#include <iostream>

#include "6_8.h"

using namespace std;

int
main(int argc, char const *argv[])
{
	for (int i = 0; i < 10; ++i) {
		cout << "Call count_call() " << count_call(i) << endl;
	}

	return 0;
}

size_t
count_call(int i)
{
	static size_t cnt;
	cout << "The function has been called for " << i << " times" << endl;
	return cnt++;
}