#pragma once
#ifndef bankAccount_h
#define bankAccount_h
#include <string>
using namespace std;

class bankAccount
{
public:
    bankAccount(string n = "" , int acctNumber = 0, double bal = 0);
    int getAccountNumber();
    double getBalance();
    string getName();
    void setName(string n);
    virtual void withdraw(double amount);
    void deposit(double amount);
    virtual void createMonthlyStatement() = 0;
    virtual void print();

protected:
    int accountNumber;
    string name;
    double balance;
    string type;
};

#endif


