#include <iostream>
#include <memory>

using namespace std;

struct connection {
	string ip;
	int port;

	connection (string _ip, int _port) : ip(_ip), port(_port) {}
};

struct destination {
	string ip;
	int port;

	destination (string _ip, int _port) : ip(_ip), port(_port) {}
};

connection
connect(destination *d)
{
	cout << "connect: " << d->ip << " " << d->port << endl;

	shared_ptr<connection> p(new connection(d->ip, d->port));

	return *p;
}

void
disconnect(connection *c)
{
	cout << "destination: " << c->ip << " " << c->port << endl;
}

void
f(destination *dest)
{
	connection c = connect(dest);

	shared_ptr<connection> p(&c, [](connection *conn){
		cout << "lambda: end_connect" << endl;
		disconnect(conn);
	});
}

int
main(int argc, char const *argv[])
{
	destination dest("192.168.5.111", 5555);

	f(&dest);

	return 0;
}