#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

#include <iostream>

using namespace std;

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
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

class ProductB : public Product
{
public:
	void show() override {
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

class Factory
{
public:
	virtual Product* createProduct() = 0;
	virtual ~Factory() {}
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

#endif