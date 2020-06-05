#include "bankAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;
bankAccount::bankAccount(string n, int acctNumber, double bal)
{
	name = n;
	accountNumber = acctNumber;
	balance = bal;

}

int bankAccount::getAccountNumber()
{
	return accountNumber;
}

double bankAccount::getBalance()
{
	return 0.0;
}

string bankAccount::getName()
{
	return name;
}

void bankAccount::setName(string n)
{
	name = n;
}

void bankAccount::withdraw(double amount)
{
	if (balance >= amount) {
		balance -= amount;
		cout << name << " (Account Number " << accountNumber << ") has withdrawn " << amount << ". " << endl;
	}
	else {
		cout << name << " (Account Number " << accountNumber << ") not enough money to withdraw." << endl;
	}

}

void bankAccount::deposit(double amount)
{
	balance = balance + amount;

	cout << "Your new balance is " << balance << endl;
}

void bankAccount::print()
{
	cout << "========================== Bank Info ============================" << endl;
	cout << setw(7) << left << "Name"
		<< setw(17) << right << "Account #"
		<< setw(17) << right << "Balance" << endl;

	cout << setw(7) << left << name
		<< setw(17) << right << accountNumber
		<< setw(17) << right << setprecision(2) << fixed << balance << endl;
}

