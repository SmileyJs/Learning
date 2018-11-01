#include <iostream>

class Prodcut
{
public:
	virtual void use() = 0;
};

class ConcreteProductA : public Prodcut
{
public:
	void use() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

class ConcreteProductB : public Prodcut
{
public:
	void use() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

typedef enum TYPE {
	TYPEA = 0,
	TYPEB,
} factory_type;

class Factory
{
public:
	static Prodcut* createProduct(factory_type t) {
		if (TYPEA == t) {
			return new ConcreteProductA(); 
		}
		else if (TYPEB == t) {
			return new ConcreteProductB();
		}
		else {
			return nullptr;
		}
	}
	
};

int
main(int argc, char const *argv[])
{
	Prodcut* a = Factory::createProduct(TYPEA);
	a->use();

	Prodcut* b = Factory::createProduct(TYPEB);
	b->use();

	return 0;
}