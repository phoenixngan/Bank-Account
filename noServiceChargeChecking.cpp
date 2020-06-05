#include "noServiceChargeChecking.h"
#include "iostream"
#include "iomanip"
using namespace std;
noServiceChargeChecking::noServiceChargeChecking(string n, int acctNumber, double bal):checkingAccount(n, acctNumber, bal)
{
	minimumBalance = MIN_BALANCE;
	interestRate = INTEREST_RATE;
}
noServiceChargeChecking::noServiceChargeChecking(string n, int acctNumber, double bal, double minBalance, double intRate) : checkingAccount(n, acctNumber, bal) {
	minimumBalance = minBalance;
	interestRate = intRate;
}
double noServiceChargeChecking::getMinimumBalance() {
	return minimumBalance;
}
void noServiceChargeChecking::setMinimumBalance(double minBalance) {
	minimumBalance = minBalance;
}
bool noServiceChargeChecking::verifyMinimumBalance(double amount) {
	if (balance >= minimumBalance) {
		return true;
	}
	return false;
}
void noServiceChargeChecking::writeCheck(double amount) {
	if (verifyMinimumBalance(amount)) {
		balance = balance - amount;
		cout << "Your check has been written for " << amount << "." << endl;
	}
	else {
		cout << "Account Number: " << accountNumber << " not enough money to write check." << endl;
	}
}
void noServiceChargeChecking::withdraw(double amount){
	if (verifyMinimumBalance(amount)) {
		balance = balance - amount;
		cout << name << " (Account Number " << accountNumber << ") has withdrawn " << amount << ". " << endl;
	}
	else {
		cout << name << " (Account Number " << accountNumber << ") not enough money to withdraw." << endl;
	}
}
void noServiceChargeChecking::createMonthlyStatement() {
	balance = (balance * (1 + interestRate));
}
void noServiceChargeChecking::print() {
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