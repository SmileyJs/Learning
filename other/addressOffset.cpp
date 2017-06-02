#include <iostream>

using namespace std;

class A
{
public:
	A() : m_a(1), m_b(2) {}

	void func() {
		// cout << m_a << m_b << endl;

		cout << __PRETTY_FUNCTION__ << endl;
	}

	int m_a;
	int m_b;
};

class B
{
public:
	B() : m_c(3) {}

	void func() {
		cout << m_c << endl;
	}

	int m_c;
};

int
main(int argc, char const *argv[])
{
	A a;
	B* pb = (B*)(&a);

	pb->func();

	B b;
	A* pa = (A*)(&b);

	pa->func();

	printf("%p\n", &A::m_a);
	printf("%p\n", &A::m_b);

	printf("%p\n", &B::m_c);

	cout << *(int*)&a << endl;
	cout << *(int*)&b << endl;

	A* pa2;
	pa2->func();

	return 0;
}