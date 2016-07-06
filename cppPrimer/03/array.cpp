#include <iostream>
#include <vector>
#include <iterator>

//using namespace std; 

using std::cout;
using std::cin;
using std::endl;
using std::begin;
using std::end;
using std::vector;

bool compare(int *const pStart1, int *const pEnd1, int *const pStart2, int *const pEnd2);

int
main(int argc, char* argv[])
{
	constexpr size_t array_size = 5;

	int a[array_size];

	for (size_t i = 0; i < array_size; ++i) {
		a[i] = i;
	} 
	
	int *pBegin = begin(a);
	int *pEnd = end(a);

	for (int *i = pBegin; i != pEnd; ++i) {
		cout << *i << endl;
	}

	int b[array_size] = {0, 1, 2, 3, 5};

	if (compare(begin(a), end(a), begin(b), end(b))) {
		cout << "The two arrays are equal!" << endl;
	}
	else {
		cout << "The two arrays are not equal!" << endl;
	}

	vector<char> c = {'c', 'd', 'e'};
	vector<char> d = {'c', 'd', 'e'};

	if (c == d) {
		cout << "The two vectors are equal!" << endl;
	}
	else {
		cout << "The two vectors are not equal!" << endl;
	}

/**
	auto b(a);

	cout << "*b = " << *b << "b = " << b << endl;
	cout << "*a = " << *a << "a = " << a << endl;

	decltype(a) c(a);
	for (int i : c) {
		cout << i << endl;
	}
 */
/**
	for (int i : a) {
		cout << i << endl;
	}

	int b[10];

	for (int i = 0; i < 10; ++i) {
		b[i] = a [i];
	}

	for (int i : b) {
		cout << "b[] = " << i << endl; 
	}

	vector<int> v1(10);

	for (vector<int>::iterator i = v1.begin(); i !=v1.end(); ++i) {
		*i = i - v1.cbegin();
	}

	vector<int> v2 = v1;

	for (int i : v2) {
		cout << "v2 = " << i << endl;
	}
 */

	return 0;
}

bool
compare(int *const pStart1, int *const pEnd1, int *const pStart2, int *const pEnd2)
{
	if ((pEnd1 - pStart1) != (pEnd2 - pStart2)) {
		return false;
	}
	else {
		for (int i = 0; i <= pEnd1 - pStart1; ++i) {
			if (*(pStart1 + i) != *(pStart2 + i))
				return false;
		}
	}
	
	return true;
}
