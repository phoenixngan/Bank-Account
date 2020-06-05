#include "highInterestChecking.h"
#include "iomanip"
#include "iostream"
using namespace std;
highInterestChecking::highInterestChecking(string n, int acctNumber, double bal):noServiceChargeChecking( n , acctNumber, bal)
{
	interestRate = INTEREST_RATE;
	minimumBalance = MIN_BALANCE;
}
highInterestChecking::highInterestChecking(string n, int acctNumber, double bal, double minBal, double intRate) : noServiceChargeChecking(n, acctNumber, bal) {
	interestRate = intRate;
	minimumBalance = minBal;
}
double highInterestChecking::getInterestRate() {
	return interestRate;
}
void highInterestChecking::setInterestRate(double intRate) {
	interestRate = intRate;
}
void highInterestChecking::postInterest() {
	balance = (balance * (1 + interestRate));
}
void highInterestChecking::createMonthlyStatement() {
	postInterest();
}
void highInterestChecking::print() {
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