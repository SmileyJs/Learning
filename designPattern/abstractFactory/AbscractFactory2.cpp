#include <iostream>

class ProductA
{
public:
	virtual void use() = 0;
};

class ProductB
{
public:
	virtual void use() = 0;
};

class Product1A : public ProductA 
{
public:
	void use() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

class Product1B : public ProductB
{
public:
	void use() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};


class Product2A : public ProductA
{
public:
	void use() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

class Product2B : public ProductB
{
public:
	void use() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

class Factory
{
public:
	virtual ProductA* createProductA() = 0;
	virtual ProductB* createProductB() = 0;
};

class Factory1 : public Factory
{
public:
	ProductA* createProductA() {
		return new Product1A();
	}

	ProductB* createProductB() {
		return new Product1B();
	}
};

class Factory2 : public Factory
{
public:
	ProductA* createProductA() {
		return new Product2A();
	}

	ProductB* createProductB() {
		return new Product2B();
	}
};


int
main(int argc, char const *argv[])
{
	Factory* f1 = new Factory1();
	ProductA* pA1 = f1->createProductA();
	ProductB* pB1 = f1->createProductB();

	pA1->use();
	pB1->use();

	Factory* f2 = new Factory2();
	ProductA* pA2 = f2->createProductA();
	ProductB* pB2 = f2->createProductB();

	pA2->use();
	pB2->use();

	return 0;
}