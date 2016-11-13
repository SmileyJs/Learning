#include <iostream>
#include <initializer_list>
#include <cstdlib>
#include <vector>

using namespace std;

// 6-1
int fact(int);

// 6-2
void swap(int*, int*);
void reset(int&);
void swapRef(int&, int&);
bool bHasCapitalLetter(const string &);
void changeLowerLetter(string &);
string::size_type findChar(const string &, char, int &);
int compareInt(const int, const int *);
void swapPointer(int *&, int *&);

void print(const int*);
void print(const char*);
void print(const int*, const int*);
void print(const int*, size_t);
void print(const int(&)[2]);
void print(const int (&ia)[10]);

int numberSum(initializer_list<int>);

// 6-3
bool str_subRange(const string &, const string &);
int factorial(int);
void vectorRecursion(vector<int>::iterator, vector<int>::iterator);
string make_plural(size_t ctr, const string &word, const string &ending = "s");

// 6-4
inline bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}
void printVec(vector<int> &);

// 6-6
void f();
void f(int);
void f(int, int);
void f(double, double);

// 6-7
int add(const int&, const int&);
int dec(const int&, const int&);
int multi(const int&, const int&);
int div(const int&, const int&);
