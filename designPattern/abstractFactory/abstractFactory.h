#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <iostream>

using namespace std;

class Product
{
public:
	virtual void show() = 0;
	virtual ~Product() {}
};

class ProductA1 : public Product
{
public:
	void show() override {
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

class ProductA2 : public Product
{
public:
	void show() override {
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

class ProductB1 : public Product
{
public:
	void show() override {
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

class ProductB2 : public Product
{
public:
	void show() override {
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

class Factory
{
public:
	virtual Product* createProductA() = 0;
	virtual Product* createProductB() = 0;
	virtual ~Factory() {}
};

class Factory1 : public Factory
{
public:
	Product* createProductA() {
		return new ProductA1();
	}

	Product* createProductB() {
		return new ProductB1();
	}
};

class Factory2 : public Factory
{
public:
	Product* createProductA() {
		return new ProductA2();
	}

	Product* createProductB() {
		return new ProductB2();
	}
};

#endif