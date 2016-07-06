#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;

int
main(void)
{
	constexpr size_t rowCnt = 3;
	constexpr size_t colCnt = 4;

	int a[rowCnt][colCnt];

/**
	for (size_t i = 0; i != rowCnt; ++i) {
		for (size_t j = 0; j!= colCnt; ++j) {
			a[i][j] = colCnt * i + j;
		}
	}
*/
	int count = 0;
	
	for (auto &i : a) {
		for (auto &j : i) {
			j = count;
			++count;
		}
	}	
/**
	for (size_t i = 0; i != rowCnt; ++i) {
		for (size_t j = 0; j!= colCnt; ++j) {
			cout << a[i][j] << endl;
		}
	}
 */
/**
	for (auto &i : a) {
		for (auto k : i) {
			cout << k << endl;
		}
	}
 */
/**
	for (auto p = a; p != a + 3; ++p) {
		for (auto q = *p; q != *p + 4; ++q) {
			cout << *q << ' ';
		}
		cout << endl;
	}

	for (auto p = begin(a); p != end(a); ++p) {
		for (auto q = begin(*p); q != end(*p); ++q) {
			cout << *q << ' ';	
		}
		cout << endl;
	}

	typedef int int_array[colCnt];

	for (int_array *p = a; p != a + 3; ++p) {
		for (int *q = *p; q != *p + 4; ++q) {
			cout << *q << ' ';
		}
		cout << endl;
	}
 */
	
	/** 3-4-5 **/
	for (auto &i : a) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << endl;
	}

	/** 3-4-3 **/
	for (size_t i = 0; i != rowCnt; ++i) {
		for (size_t j = 0; j != colCnt; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

	/** 3-4-5 **/
	for (auto p = begin(a); p != end(a); ++p) {
		for (auto q = begin(*p); q != end(*p); ++q) {
			cout << *q << ' ';
		}
		cout << endl;
	}

	/** 3-4-4 **/ 
//	typedef int int_array[colCnt];
	using int_array = int[4];
	for (int_array *p = a; p != a + rowCnt; ++p) {
		for (int *q = *p; q != *p + colCnt; ++q) {
			cout << *q << ' ';
		}
		cout << endl;
	}

	for (int_array &i : a) {
		for (int j : i) {
			cout << j << ' ';
		}
		cout << endl;
	}

	/** 3-4-3 **/
	for (int (&i)[colCnt] : a) {
		for (int j : i) {
			cout << j << ' ';
		}
		cout << endl;
	}

	for (int (*i)[colCnt] = begin(a); i != end(a); ++i) {
		for (int *j = begin(*i); j != end(*i); ++j) {
			cout << *j << ' ';
		}
		cout << endl;
	}

	return 0;
}
