#pragma once
#ifndef noServiceChargeChecking_H
#define noServiceChargeChecking_H

#include <string>
#include "checkingAccount.h"
using namespace std;

class noServiceChargeChecking : public checkingAccount
{
public:
    noServiceChargeChecking(string n, int acctNumber, double bal);
    noServiceChargeChecking(string n, int acctNumber, double bal,
        double minBalance, double intRate);

    double getMinimumBalance();
    void setMinimumBalance(double minBalance);
    bool verifyMinimumBalance(double amount);
    void writeCheck(double amount);
    void withdraw(double amount);
    virtual void createMonthlyStatement();
    virtual void print();

protected:
    double minimumBalance;
    double interestRate;

private:
    static constexpr double MIN_BALANCE  = 1000.00;
    static constexpr double INTEREST_RATE = 0.02;
};

#endif

