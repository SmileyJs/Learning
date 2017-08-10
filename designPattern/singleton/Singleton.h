#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton* getInstance() {
		cout << __PRETTY_FUNCTION__ << endl;
		static Singleton m_instance;
		return &m_instance;
	}

	static void destoryInstance() {
		cout << __PRETTY_FUNCTION__ << endl;
	}

	void test() {
		cout << __PRETTY_FUNCTION__ << endl;
	}

private:
	Singleton() {
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

#endif