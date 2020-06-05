#pragma once
#ifndef highInterestSavings_H
#define highInterestSavings_H

#include <string>
#include "savingsAccount.h"
using namespace std;

class highInterestSavings : public savingsAccount
{
public:
    highInterestSavings(string n, int acctNumber, double bal);
    highInterestSavings(string n, int acctN, double balance, double intRate, double minBalance);
    double getMinimumBalance();
    bool verifyMinimumBalance(double amount);
    virtual void withdraw(double amount);
    virtual void print();

protected:
    double minimumBalance;

private:
    static constexpr double MINIMUM_BALANCE = 2500.00;
    static constexpr double INTEREST_RATE = 0.05;
};

#endif