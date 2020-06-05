#pragma once
#ifndef savingsAccount_H
#define savingsAccount_H

#include <string>
#include "bankAccount.h"

using namespace std;

class savingsAccount : public bankAccount
{
public:
    savingsAccount(string n, int acctNumber, double bal);

    savingsAccount(string n, int acctNumber, double bal, double intRate);

    double getInterestRate();
    void setInterestRate(double rate);
    void postInterest();
    virtual void createMonthlyStatement();
    virtual void print();

protected:
    double interestRate;

private:
    static constexpr double INTEREST_RATE = 0.03;

};

#endif