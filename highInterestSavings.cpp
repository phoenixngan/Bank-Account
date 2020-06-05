#include "iostream"
#include "iomanip"
#include "highInterestSavings.h"
using namespace std;
highInterestSavings::highInterestSavings(string n, int acctNumber, double bal) : savingsAccount(n, acctNumber,bal)
{
	interestRate = INTEREST_RATE;
	minimumBalance = MINIMUM_BALANCE;
}

highInterestSavings::highInterestSavings(string n, int acctN, double balance, double intRate, double minBalance) : savingsAccount(n, acctN, balance, intRate)
{
	interestRate = intRate;
	minimumBalance = minBalance;
}

double highInterestSavings::getMinimumBalance()
{
	return minimumBalance;
}

bool highInterestSavings::verifyMinimumBalance(double amount)
{
	if(balance >= minimumBalance){
		return true;
	}
	return false;
}

void highInterestSavings::withdraw(double amount)
{
	if (verifyMinimumBalance(amount)) {
		balance = balance - amount;
		cout << name << " (Account Number " << accountNumber << ") has withdrawn " << amount << ". " << endl;
	}
	else {
		cout << name << " (Account Number " << accountNumber << ") does not have enough money withdraw." << endl;
	}
}

void highInterestSavings::print()
{
	cout << "========================== Bank Info ============================" << endl;
	cout << setw(7) << left << "Name"
		<< setw(17) << right << "Account #"
		<< setw(17) << right << "Balance" 
		<< setw(17) << right << "Min Balance" << endl;

	cout << setw(7) << left << name
		<< setw(17) << right << accountNumber
		<< setw(17) << right << setprecision(2) << fixed << balance 
		<< setw(17) << right << setprecision(2) << fixed << minimumBalance << endl;
}
