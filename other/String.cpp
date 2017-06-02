	#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
	String(const char* str = NULL);
	String(const String& other);

	~String();
	
	String& operator=(const String& other);

private:
	char *m_data;
};

String::String(const char* str)
{
	cout << __PRETTY_FUNCTION__ << endl;

	if (NULL == str) {
		m_data = new char[1];
		m_data[0] = '\0';
	}
	else {
		int len = strlen(str);
		m_data = new char[len+1];
		strcpy(m_data, str);
	}
}

String::String(const String& other)
{
	cout << __PRETTY_FUNCTION__ << endl;
		
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
}

String::~String()
{
	cout << __PRETTY_FUNCTION__ << endl;

	delete m_data;
}

String&
String::operator=(const String& other)
{
	cout << __PRETTY_FUNCTION__ << endl;

	if (this != &other) {
		delete m_data;

		m_data = new char[strlen(other.m_data) + 1];
		strcpy(m_data, other.m_data);
	}

	return *this;
}

int
main(int argc, char const *argv[])
{
	String a;
	String b("bbb");
	a = b;
	
	return 0;
}
