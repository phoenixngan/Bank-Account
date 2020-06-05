#pragma once
#ifndef highInterestChecking_H
#define highInterestChecking_H

#include <string>
#include "noServiceChargeChecking.h"
using namespace std;

class highInterestChecking : public noServiceChargeChecking
{
public:
    highInterestChecking(string n, int acctNumber, double bal);
    highInterestChecking(string n, int acctNumber, double bal,
        double minBal, double intRate);
    double getInterestRate();
    void setInterestRate(double intRate);
    void postInterest();
    void createMonthlyStatement();
    virtual void print();

private:
    static constexpr double INTEREST_RATE = 0.05;
    static constexpr double MIN_BALANCE = 5000.00;
};

#endif

