#include <iostream>
#include <string>
#include <map>
#include <algorithm>

class Member;

class ChatRoom
{
public:
	typedef std::map<int, Member*> MemberMap;

	virtual void reg(int id, Member* m) = 0;
	virtual void operate(int id, const std::string& s) = 0;

protected:
	MemberMap m_map;
};

class Member
{
public:
	void setMediator(ChatRoom* cr) {
		m_chatroom = cr;
	}

	virtual void sendMsg(int, const std::string&) = 0;
	virtual void receiveMsg(const std::string&) = 0;

protected:
	ChatRoom* m_chatroom;
};

class MemberA : public Member
{
public:
	void sendMsg(int id, const std::string& s) {
		std::cout << "MemberA sendMsg id = " << id << " msg = " << s << std::endl;
		m_chatroom->operate(id, s);
	}

	void receiveMsg(const std::string& s) {
		std::cout << "MemberA receiveMsg msg = " << s << std::endl;
	}
};

class MemberB : public Member
{
public:
	void sendMsg(int id, const std::string& s) {
		std::cout << "MemberB sendMsg id = " << id << " msg = " << s << std::endl;
		m_chatroom->operate(id, s);
	}

	void receiveMsg(const std::string& s) {
		std::cout << "MemberB receiveMsg msg = " << s << std::endl;
	}
};

class ConcreteChatRoom : public ChatRoom
{
public:
	void reg(int id, Member* m) {
		std::cout << __PRETTY_FUNCTION__ << std::endl;

		auto it = m_map.find(id);
		if (it != m_map.end())
			return;

		m_map.insert(std::make_pair(id, m));
		m->setMediator(this);
	}

	void operate(int id, const std::string& s) {
		std::cout << __PRETTY_FUNCTION__ << std::endl;

		auto it = m_map.find(id);

		if (it == m_map.end())
			return;

		it->second->receiveMsg(s);
	}
};


int
main(int argc, char const *argv[])
{
	Member* a = new MemberA();
	Member* b = new MemberB();

	ChatRoom* cr = new ConcreteChatRoom();
	cr->reg(1, a);
	cr->reg(2, b);

	a->sendMsg(2, "hello!");
	b->sendMsg(1, "world!");


	return 0;
}