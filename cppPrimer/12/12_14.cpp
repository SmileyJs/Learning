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
};

connection
connect(destination *dest)
{
	cout << "connect: " << dest->ip << " " << dest->port << endl; 

	shared_ptr<connection> p(new connection(dest->ip, dest->port));

	return *p;
}

void
disconnect(connection *p)
{
	cout << "disconenct: " << p->ip << " " << p->port << endl;
}

void
end_connect(connection *c)
{
	cout << "end_connect" << endl;
	disconnect(c);
}

void
f(destination *dest)
{
	connection c = connect(dest);

	shared_ptr<connection> p(&c, end_connect);
}

int
main(int argc, char const *argv[])
{
	destination dest("192.168.5.100", 5555);

	f(&dest);

	return 0;
}