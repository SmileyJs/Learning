#include <iostream>
#include <set>
#include <string>

using namespace std;

class Message {
public:
	explicit Message(const string &s = "") : content(s) {}
	Message(const Message &cp);
	Message &operator=(const Message &cp);
	~Message();

	save(Folder &);
	remove(Folder &);

private:
	string content;
	set<Folder*> folder;
	void addToFolder(Message &);
	void removeFromFolder();
}

class Folder {
public:

private:

}

