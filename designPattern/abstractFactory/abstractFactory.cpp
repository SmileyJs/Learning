#include "abstractFactory.h"

int
main(int argc, char const *argv[])
{
	Factory* factory1 = new Factory1();
	Factory* factory2 = new Factory2();

	Product* productA1 = factory1->createProductA();
	Product* productB1 = factory1->createProductB();

	Product* productA2 = factory2->createProductA();
	Product* productB2 = factory2->createProductB();

	if (productA1)
		productA1->show();

	if (productB1) 
		productB1->show();

	if (productA2)
		productA2->show();

	if (productB2)
		productB2->show();

	if (productA1) {
		delete productA1;
		productA1 = nullptr;
	}

	if (productA2) {
		delete productA2;
		productA2 = nullptr;
	}

	if (productB1) {
		delete productB1;
		productB1 = nullptr;
	}

	if (productB2) {
		delete productB2;
		productB2 = nullptr;
	}

	if (factory1) {
		delete factory1;
		factory1 = nullptr;
	}

	if (factory2) {
		delete factory2;
		factory2 = nullptr;
	}

	return 0;
}