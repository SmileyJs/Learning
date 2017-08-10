#include "factoryMethod.h"

int
main(int argc, char const *argv[])
{
	Factory* factoryA = new FactoryA();
	Product* productA = factoryA->createProduct();

	if (productA) {
		productA->show();
	}

	Factory* factoryB = new FactoryB();
	Product* productB = factoryB->createProduct();

	if (productB) {
		productB->show();
	}

	if (productA) {
		delete productA;
		productA = nullptr;
	}

	if (productB) {
		delete productB;
		productB = nullptr;
	}

	if (factoryA) {
		delete factoryA;
		factoryA = nullptr;
	}

	if (factoryB) {
		delete factoryB;
		factoryB = nullptr;
	}

	return 0;
}