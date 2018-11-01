#include <iostream>

class Receiver
{
public:
	void action() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

class Command
{
public:
	virtual void execute() = 0;
};

class CommandA : public Command
{
public:
	CommandA(Receiver* r) : m_receiver(r) {}

	void execute() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		m_receiver->action();
	}
private:
	Receiver* m_receiver;
};

class Invoker 
{
public:
	Invoker(Command* c) : m_pCommand(c) {}

	void call() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		m_pCommand->execute();
	}
private:
	Command* m_pCommand;
};

int
main(int argc, char const *argv[])
{
	Receiver* recv = new Receiver();
	Command* comd = new CommandA(recv);
	Invoker* inv = new Invoker(comd);

	inv->call();

	return 0;
}