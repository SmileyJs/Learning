#include <iostream>
#include <vector>
#include <algorithm>

// class AutoFinalizer
// {
// public:
// 	AutoFinalizer(void*);
// 	~AutoFinalizer(func());
// private:
// 	void func() {
// 		std::cout << "func" << std::endl;
// 	}
// };

class ShortThan
{
public:
	explicit ShortThan(int i) : a(i) {}

	bool operator()(int n) {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return n < a;
	}

private:
	int a;
};

int
main(int argc, char const *argv[])
{
	std::vector<int> vecInt = {1, 2, 3, 4, 5};

	for (int i : vecInt) {
		std::cout << i << std::endl;
	}	

	int n = std::count_if(vecInt.begin(),vecInt.end(), ShortThan(4));

	std::cout << n << " num small than 4" << std::endl;

	return 0;
}