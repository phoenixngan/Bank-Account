#include "savingsAccount.h"
#include "iomanip"
#include "iostream"
using namespace std;

savingsAccount::savingsAccount(string n, int acctNumber, double bal):bankAccount(n, acctNumber, bal)
{
	interestRate = INTEREST_RATE;

}

savingsAccount::savingsAccount(string n, int acctNumber, double bal, double intRate):bankAccount(n, acctNumber, bal)
{
	interestRate = intRate;
}

double savingsAccount::getInterestRate()
{
	return interestRate;
}

void savingsAccount::setInterestRate(double rate)
{
	interestRate = rate;
}

void savingsAccount::postInterest()
{
	balance = (balance * (1 + interestRate));
}

void savingsAccount::createMonthlyStatement()
{
	postInterest();
}

void savingsAccount::print()
{
	cout << "========================== Bank Info ============================" << endl;
	cout << setw(7) << left << "Name"
		<< setw(17) << right << "Account #"
		<< setw(17) << right << "Balance" << endl;

	cout << setw(7) << left << name
		<< setw(17) << right << accountNumber
		<< setw(17) << right << setprecision(2) << fixed << balance << endl;
}
