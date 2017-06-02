#include <iostream>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;

class Modulus
{
public:
	int operator()(int i, int j) {
		return i%j;
	}
};

int
divide(int i, int j)
{
	return i/j;
}

void insertFunc(map<string, function<int(int, int)>> &m)
{
	auto multiply = [](int i, int j) { return i*j; };
	int(*fp)(int, int) = divide;
	plus<int> intAdd;

	m.insert({"+", intAdd});
	m.insert({"-", [](int i, int j) { return i - j; }});
	m.insert({"*", multiply});
	m.insert({"/", fp});
	m.insert({"%", Modulus()});
}

int
main(int argc, char const *argv[])
{
	map<string, function<int(int, int)>> binOps;

	insertFunc(binOps);

	cout << "+: " << binOps["+"](2, 4) << endl;
	cout << "-: " << binOps["-"](2, 4) << endl;
	cout << "*: " << binOps["*"](2, 4) << endl;
	cout << "/: " << binOps["/"](2, 4) << endl;
	cout << "%: " << binOps["%"](2, 4) << endl;

	return 0;
}