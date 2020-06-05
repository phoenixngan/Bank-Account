#pragma once
#ifndef checkingAccount_H
#define checkingAccount_H

#include <string>

#include "bankAccount.h"

using namespace std;

class checkingAccount : public bankAccount
{
public:
    checkingAccount(string n, int acctNumber, double bal);

    virtual void writeCheck(double amount) = 0;
};

#endif
