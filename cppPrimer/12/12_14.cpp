#include <iostream>
#include <memory>

using namespace std;

struct connection {
	int port;
	string ip;

	connection(string ip_, int port_) : ip(ip_), port(port_) {}
};

struct destination {
	int port;
	string ip;

	destination(string ip_, int port_) : ip(ip_), port(port_) {}
}

connection
connect()
{

}

int
main(int argc, char const *argv[])
{
	shared_ptr<connection> p();
	return 0;
}