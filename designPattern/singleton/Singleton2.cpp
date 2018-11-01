#include <iostream>

class Singleton
{
public:
	static Singleton* getInstance() {
		if (NULL == m_instance)
			return new Singleton();
		else 
			return m_instance;
	}

	void use() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

private:
	Singleton() {}
	~Singleton() {
		delete m_instance;
	}

	static Singleton* m_instance;
};

Singleton* Singleton::m_instance = NULL;

int 
main(int argc, char const *argv[])
{
	Singleton::getInstance()->use();
	return 0;
}