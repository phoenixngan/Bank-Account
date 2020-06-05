#include "serviceChargeChecking.h"
#include <iomanip>
#include <iostream>
using namespace std;
serviceChargeChecking::serviceChargeChecking(string n, int acctNumber, double bal) :checkingAccount(n, acctNumber, bal) {
	serviceChargeAccount = ACCOUNT_SERVICE_CHARGE;
	serviceChargeCheck = SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS;
	numberOfChecksWritten = 0;
}
serviceChargeChecking::serviceChargeChecking(string n, int acctNumber, double bal, double servChargeAmount, double servChargeCheck) : checkingAccount(n, acctNumber, bal) {
	serviceChargeAccount = servChargeAmount;
	serviceChargeCheck = servChargeCheck;
	numberOfChecksWritten = 0;
}
double serviceChargeChecking::getServiceChargeAccount() {
	return serviceChargeAccount;
}
void serviceChargeChecking::setServiceChargeAccount(double amount) {
	serviceChargeAccount = amount;
}
double serviceChargeChecking::getServiceChargeChecks() {
	return serviceChargeCheck;
}
void serviceChargeChecking::setServiceChargeChecks(double amount) {
	serviceChargeCheck = amount;
}
int serviceChargeChecking::getNumberOfChecksWritten() {
	return numberOfChecksWritten;
}
void serviceChargeChecking::setNumberOfChecksWritten(int num) {
	numberOfChecksWritten = num;
}
void serviceChargeChecking::postServiceCharge() {
	balance -= serviceChargeAccount;
}
void serviceChargeChecking::writeCheck(double amount) {
	balance -= amount;
	if (numberOfChecksWritten > MAXIMUM_NUM_OF_CHECKS) {
		balance -= serviceChargeCheck;
	}
	numberOfChecksWritten++;
}
void serviceChargeChecking::createMonthlyStatement() {
	postServiceCharge();
}
void serviceChargeChecking::print() {
	cout << "========================== Bank Info ============================" << endl;
	cout << setw(7) << left << "Name"
		<< setw(17) << right << "Account #"
		<< setw(17) << right << "Balance" << endl;

	cout << setw(7) << left << name
		<< setw(17) << right << accountNumber
		<< setw(17) << right << setprecision(2) << fixed << balance << endl;
}
