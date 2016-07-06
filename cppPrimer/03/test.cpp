#include <iostream>

using namespace std;

class A
{

public:
	virtual void setTest1() {
		cout << "setTest1" << endl;
		setText2();
	}
	
	virtual void setText2() {
		cout << "setText2" << endl;
	}

};

class B : public A
{
public:
	void setText1();
	void setText2() {
		cout << "setText4" << endl;
	}

};

int
main()
{
	A* a = new A();
	B* b = new B(); 

	b->setText1();

	return 0;
}
