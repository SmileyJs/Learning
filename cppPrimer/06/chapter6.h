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