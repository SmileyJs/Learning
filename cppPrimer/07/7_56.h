#include <iostream>

using std::string;

class Account{
public:
	void calcute() {
		amount += amount * interestRate;
	}
	static double rate() {return interestRate;}
	static void rate(double);

private:
	string owner;
	double amount;
	static double interestRate;
	static double initRate();
};