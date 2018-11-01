#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> 

int add(int a, int b)
{
	return a + b;
}

void print(int a, int b) {
	std::cout << a + b << std::endl;
}

class Module
{
public:
	Module(int a) : data(a) {}
	~Module(){}
	
	void operator()(int a){
		std::cout << a + data << std::endl;
	}

	void test(int a, int b) {
		std::cout << a + b << std::endl;
	}

private:
	int data;
};

int
main(int argc, char const *argv[])
{
	using namespace std::placeholders;

	std::vector<int> vec = {1, 2, 3, 4, 5};

	for_each(vec.begin(), vec.end(), [](int &n){
		return n + 20;
	});

	for (int i : vec) {
		std::cout << i << std::endl;
	}

	for_each(vec.begin(), vec.end(), std::bind(print, _1, 20));

	for (int i :vec) {
		std::cout << i << std::endl;
	}

	std::function<void(int, int)> func = std::function<void(int, int)>([](int a, int b) {
		std::cout << a + b << std::endl;
	});

	std::function<void(int, int)> funcP = &print;

	for_each(vec.begin(), vec.end(), std::bind(func, 10, _1));

	Module m(5);
	for_each(vec.begin(), vec.end(), m);

	for_each(vec.begin(), vec.end(), std::bind(&Module::test, &m, _1, 50));

	funcP(1, 2);

	for_each(vec.begin(), vec.end(), std::bind(funcP, _1, 8));

	return 0;
}