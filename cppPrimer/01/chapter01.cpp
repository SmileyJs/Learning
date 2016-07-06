#include <iostream>

int main() {
	std::cout << "Please input two numbers!" << std::endl;
	int a = 0;
	int b = 0;

	std::cin >> a >> b;
	int sum = a + b;

	std::cout << "The sum of " << a << " and " << b << " is " << sum << std::endl;
	
	return 1;
}
