#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template <typename T, typename... Args>
shared_ptr<T> self_make_shared(Args &&... args)
{
	shared_ptr<T> p(new T(std::forward<Args>(args)...));

	return p;
}

int
main(int argc, char const *argv[])
{
	// shared_ptr<vector<int>> p = self_make_shared(11, 22, 33, 44, 55);

	auto p = self_make_shared<int>(11);

	cout << *p << endl;

	auto p2 = self_make_shared<string>("haha");

	cout << *p2 << endl;

	auto p3 = self_make_shared<string>(10, 'c');

	cout << *p3 << endl;

	return 0;
}