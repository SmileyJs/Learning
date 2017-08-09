#include "SimpleFactory.h"

SimpleFactory* SimpleFactory::m_instance = nullptr;

SimpleFactory*
SimpleFactory::getInstance()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	if (!m_instance) {
		m_instance = new SimpleFactory();
	}

	return m_instance;
}

Product*
SimpleFactory::createProduct(PRODUCTTYPE type)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	switch (type) {
	case TYPE_A:
		return new ProductA();
		break;
	case TYPE_B:
		return new ProductB();
		break;
	case TYPE_C:
		return new ProductC();
		break;
	default:
		return nullptr;
		break;
	}
}

void
SimpleFactory::destroyInstance()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	if (m_instance) {
		delete m_instance;
		m_instance = nullptr;
	}
}

int
main(int argc, char const *argv[])
{
	Product* a = SIMPLEFACTORY_INST->createProduct(TYPE_A);
	if (a) a->show();

	Product* b = SIMPLEFACTORY_INST->createProduct(TYPE_B);
	if (b) b->show();

	Product* c = SIMPLEFACTORY_INST->createProduct(TYPE_C);
	if (c) c->show();

	SimpleFactory::destroyInstance();

	delete a;
	a = nullptr;

	delete b;
	b = nullptr;

	delete c;
	c = nullptr;

	return 0;
}