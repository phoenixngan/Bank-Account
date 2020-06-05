#pragma once
#ifndef serviceChargeChecking_H
#define serviceChargeChecking_H

#include <string>
#include "checkingAccount.h"

using namespace std;

class serviceChargeChecking : public checkingAccount
{
public:
    serviceChargeChecking(string n, int acctNumber, double bal);
    serviceChargeChecking(string n, int acctNumber, double bal,
        double servChargeAmount,
        double servChargeCheck);

    double getServiceChargeAccount();
    void setServiceChargeAccount(double amount);
    double getServiceChargeChecks();
    void setServiceChargeChecks(double amount);
    int getNumberOfChecksWritten();
    void setNumberOfChecksWritten(int num);
    void postServiceCharge();
    void writeCheck(double amount);
    virtual void createMonthlyStatement();
    virtual void print();

protected:
    double serviceChargeAccount;
    double serviceChargeCheck;
    int numberOfChecksWritten;

private:
    static constexpr double ACCOUNT_SERVICE_CHARGE = 10.00;
    static constexpr int MAXIMUM_NUM_OF_CHECKS = 5;
    static constexpr double SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS = 5;
};

#endif
