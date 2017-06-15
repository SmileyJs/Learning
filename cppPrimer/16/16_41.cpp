#include <iostream>
#include <type_traits>

using namespace std;

template <typename T>
auto sumA(const T& a, const T& b) -> typename remove_reference<decltype(a)>::type
{
	cout << __PRETTY_FUNCTION__ << endl;
	return a + b;
}

template <typename T>
auto sum(const T& a, const T& b) -> typename remove_reference<decltype(a+b)>::type
{
	cout << __PRETTY_FUNCTION__ << endl;
	return a + b;
} 

int
main(int argc, char const *argv[])
{
	cout << sumA(1, 2) << endl;
	cout << sum<string>("aa", "bbb") << endl;

	cout << sumA(9223372036854775807, 9223372036854775807) << endl;
	cout << sum(9223372036854775807, 9223372036854775807) << endl;

	return 0;
}