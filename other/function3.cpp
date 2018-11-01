#include <iostream>
#include <vector>
#include <functional>

typedef std::function<void(void)> Func;

void print(int a)
{
	std::cout << a << std::endl;
}

class A
{
public:
	virtual void req(int) = 0;
	virtual void res(std::string, int) = 0;
};

class B : public A
{
public:
	void req(int a) {
		std::cout << "B req " << a << std::endl; 
	}

	void res(std::string s, int a ) {
		std::cout << "B res " << s << " " << a << std::endl;
	}
};

class C : public A
{
public:
	void req(int a) {
		std::cout << "C req " << a << std::endl;
	}

	void res(std::string s, int a) {
		std::cout << "C res " << s << " " << a << std::endl;
	}
};

typedef std::function<void(int)> ReqFunc;
typedef std::function<void(std::string)> ResFunc;

using namespace std::placeholders;

#define FUNCTION_REQ(...) ReqFunc(std::bind(&A::req, _1, _2))
#define FUNCTION_RES(...) ResFunc(std::bind(&A::res, _1, _2, _3))

int
main(int argc, char const *argv[])
{
	Func f(std::bind(&print, 9));
	f();

	A* t1 = new B;
	A* t2 = new C;

	t1->req(1);
	t1->res("11", 11);

	t2->req(2);
	t2->res("22", 22);

	FUNCTION_REQ(t1, 3);

	return 0;
}