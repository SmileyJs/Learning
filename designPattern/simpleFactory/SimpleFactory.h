#ifndef SIMPLEFACTORY_H
#define SIMPLEFACTORY_H

#include <iostream>

enum PRODUCTTYPE{
	TYPE_A = 0,
	TYPE_B,
	TYPE_C
};

class Product
{
public:
	virtual void show() = 0;
	virtual ~Product() {}
};

class ProductA : public Product
{
public:
	void show() override {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

class ProductB : public Product
{
public:
	void show() override {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

class ProductC : public Product
{
public:
	void show() override {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

#define SIMPLEFACTORY_INST SimpleFactory::getInstance()

class SimpleFactory
{
public:
	static SimpleFactory* getInstance();
	static void destroyInstance();
	
	Product* createProduct(PRODUCTTYPE);

private:
	static SimpleFactory* m_instance;
};

#endif