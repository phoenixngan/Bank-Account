#include "certificateOfDeposit.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
certificateOfDeposit::certificateOfDeposit(string n, int acctNumber, double bal) :bankAccount(n, acctNumber, bal)
{
	interestRate = INTEREST_RATE;
	maturityMonths = NUMBER_OF_MATURITY_MONTHS;
	cdMonth = 0;
}

certificateOfDeposit::certificateOfDeposit(string n, int acctNumber, double bal, double intRate, int maturityMon) : bankAccount(n, acctNumber, bal)
{
	interestRate = intRate;
	maturityMonths = maturityMon;
	cdMonth = 0;
}

double certificateOfDeposit::getInterestRate()
{
	return interestRate;
}

void certificateOfDeposit::setInterestRate(double rate)
{
	interestRate = rate;
}

double certificateOfDeposit::getCurrentCDMonth()
{
	return cdMonth;
}

void certificateOfDeposit::setCurrentCDMonth(int month)
{
	cdMonth = month;
}

double certificateOfDeposit::getMaturityMonths()
{
	return maturityMonths;
}

void certificateOfDeposit::getMaturityMonths(int month)
{
	maturityMonths = month;
}

void certificateOfDeposit::postInterest()
{
	balance = (balance * (1 + (interestRate)));
}

void certificateOfDeposit::withdraw(double amount)
{
		if (balance >= amount) {
			balance -= amount;
			if (cdMonth < maturityMonths) {
				int remainingMonths = maturityMonths - cdMonth;
				double fine = balance * (1 + ((remainingMonths) *interestRate)) - balance; // fine is equal to the amount of interest that would have been earned for the maturity months
				balance -= fine;
				cout << name << " (Account Number " << accountNumber << ") has received a penalty of " << fine << " due to early withdrawal penalty." << endl;
			}
			else {
				cout << name << " (Account Number " << accountNumber << ") has withdrawn " << amount << ". " << endl;
			}
		}
		else {
			cout << name << " (Account Number " << accountNumber << ") does not have enough money to withdraw." << endl;
		}
}

void certificateOfDeposit::withdraw()
{
	balance = 0;
	cout << name << " (Account Number " << accountNumber << ") has withdrawn " << balance << ". " << endl;
}

void certificateOfDeposit::createMonthlyStatement()
{
	postInterest();
	cdMonth++;
}

void certificateOfDeposit::print()
{
	cout << "========================== Bank Info ============================" << endl;
	cout << setw(7) << left << "Name"
		<< setw(17) << right << "Account #"
		<< setw(17) << right << "Balance" 
		<< setw(17) << right << "CD Month " 
		<< setw(17) << right << "Maturity Month " << endl;

	cout << setw(7) << left << name
		<< setw(17) << right << accountNumber
		<< setw(17) << right << setprecision(2) << fixed << balance 
		<< setw(17) << right << cdMonth 
		<< setw(17) << right << maturityMonths << endl;
}

