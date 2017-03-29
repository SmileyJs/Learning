#include <iostream>
#include <set>
#include <string>

using namespace std;

class Folder;

class Message {
	friend class Folder;
	friend void swap(Message &, Message &);
public:
	explicit Message(const string &s = "") : content(s) {}
	Message(const Message &);
	Message &operator=(const Message &);
	Message(Message &&) noexcept;
	Message &operator=(Message &&) noexcept;
	~Message();

	void save(Folder &);
	void remove(Folder &);

private:
	string content;
	set<Folder*> folder;
	
	void addToFolder(Message &);
	void removeFromFolder();
	void addFld(Folder *);
	void removeFld(Folder *);
	void moveFoloder(Message *);
};

void swap(Message &, Message &);

class Folder {
	friend class Message;
	friend void swap(Folder &, Folder &);

public:
	Folder() {};
	Folder(const Folder &c);
	Folder &operator=(const Folder &);
	~Folder();

private:
	set<Message*> message;

	void addMsg(Message *);
	void removeMsg(Message *);
	void addToMessage(Folder &);
	void removeFromMessage();
};

void swap(Folder &, Folder &);

Message::Message(const Message &m)
	: content(m.content)
	, folder(m.folder)
{	
	addToFolder(*this);
}

Message &
Message::operator=(const Message &m)
{
	removeFromFolder();

	content = m.content;
	folder = m.folder;

	addToFolder(*this);

	return *this;
}

Message::Message(Message &&c) noexcept
	: content(std::move(c.content))
{
	moveFoloder(&c);
}

Message &
Message::operator=(Message &&c) noexcept
{
	if (this != &c) {
		removeFromFolder();
		content = std::move(c.content);
		moveFoloder(&c);
	}

	return *this;
}

Message::~Message()
{
	removeFromFolder();
}

void
Message::moveFoloder(Message *m)
{
	folder = std::move(m->folder);
	for (auto i : folder) {
		i->removeMsg(m);
		i->addMsg(this);
	}

	m->folder.clear();
}

void
Message::addFld(Folder *f)
{
	folder.insert(f);
}

void
Message::removeFld(Folder *f)
{
	folder.erase(f);
}

void
swap(Message &lhs, Message &rhs)
{
	using std::swap;

	lhs.removeFromFolder();
	rhs.removeFromFolder();

	swap(lhs.content, rhs.content);
	swap(lhs.folder, rhs.folder);

	lhs.addToFolder(lhs);
	rhs.addToFolder(rhs);
}

Folder::Folder(const Folder &f)
	: message(f.message)
{
	addToMessage(*this);
}

Folder &
Folder::operator=(const Folder &f)
{
	message = f.message;

	removeFromMessage();
	addToMessage(*this);

	return *this;
}

Folder::~Folder()
{
	removeFromMessage();
}

void
Folder::addMsg(Message *m)
{
	message.insert(m);
}

void
Folder::removeMsg(Message *m)
{
	message.erase(m);
}

void
Folder::addToMessage(Folder &f)
{
	for (auto i : f.message) {
		i->addFld(this);
	}
}

void
Folder::removeFromMessage()
{
	for (auto i : message) {
		i->removeFld(this);
	}
}

void
Message::save(Folder &f)
{
	folder.insert(&f);
	f.addMsg(this);
}

void
Message::remove(Folder &f)
{	
	folder.erase(&f);
	f.removeMsg(this);
}

void
Message::addToFolder(Message &m)
{
	for (auto f : m.folder) {
		f->addMsg(&m);
	}
}

void
Message::removeFromFolder()
{
	for (auto f : folder) {
		f->removeMsg(this);
	}
}

void
swap(Folder &lhs, Folder &rhs)
{
	lhs.removeFromMessage();
	rhs.removeFromMessage();

	swap(lhs.message, rhs.message);

	lhs.addToMessage(lhs);
	rhs.addToMessage(rhs);
}