#include <iostream>

class Product
{
public:
	virtual void use() = 0;
};

class ProductA : public Product
{
public:
	void use() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

class ProductB : public Product
{
public:
	void use() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

class Factory
{
public:
	virtual Product* createProduct() = 0;
};

class FactoryA : public Factory
{
public:
	Product* createProduct() {
		return new ProductA();
	}
};

class FactoryB : public Factory
{
public:
	Product* createProduct() {
		return new ProductB();
	}
};

int
main(int argc, char const *argv[])
{
	Factory* fA = new FactoryA();
	Product* pA = fA->createProduct();

	pA->use();

	Factory* fB = new FactoryB();
	Product* pB = fB->createProduct();

	pB->use();

	if (!fA) {
		delete fA;
	}

	if (!pA) {
		delete pA;
	}

	if (!fB) {
		delete fB;
	}

	if (!pB) {
		delete pB;
	}
	return 0;
}