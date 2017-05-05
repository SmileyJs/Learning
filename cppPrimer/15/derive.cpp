#include <iostream>

using namespace std;

class Base
{
public:
	void pub_men() {
		cout << __PRETTY_FUNCTION__ << endl;
	}

protected:
	virtual void print() {
		cout << "Base print" << endl;
	}

	void pro_men() {
		cout << __PRETTY_FUNCTION__ << endl;
	}

	char prot_men;

private:
	int priv_men;
};

class Pub_Derv : public Base
{
public:
	char f() {
		return prot_men;
	}

	// int g() {
	// 	return priv_men;
	// }
};

class Drived_from_Public : public Pub_Derv
{
public:
	char i() {
		return prot_men;
	}
};

class Pri_derv : private Base
{
public:
	int h() {
		return prot_men;
	}
};

class Drived_form_Pricate : public Pri_derv
{
public:
	int j() {
		return prot_men;
	}
};

int main(int argc, char const *argv[])
{
	Pub_Derv d1;
	Pri_derv d2;

	d1.pub_men();
	// d2.pub_men();

	return 0;
}