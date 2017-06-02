#include <iostream>

using namespace std;

class TestA
{
public:
	TestA() {
		count ++;
	}
	~TestA() {};
	
	void print() {
		cout << count << endl;
	}

private:
	static int count;
};

int TestA::count = 0;

class TestB
{
public:
	TestB() {
		cout << __PRETTY_FUNCTION__ << endl;
	}

	TestB(int a) : m_i(a) {
		cout << __PRETTY_FUNCTION__ << endl;
	}

	~TestB() {
		cout << __PRETTY_FUNCTION__ << endl;
	}
	
private:
	int m_i;
};

TestB play(TestB tmp)
{
	cout << __PRETTY_FUNCTION__ << endl;

	return tmp;
}

int
main(int argc, char const *argv[])
{
	TestA a;
	a.print();

	TestA b;
	b.print();

	int i = 0;
	cout << i++ + ++i << endl;

	TestB temp = play(5);

	cin.get();

	return 0;
}