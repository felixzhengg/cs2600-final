/*
Group 10
Aris Sarkisian, Ethan Caoile, Felix Zheng, Micah Kang, Ricky Paque
CS 2600
*/
#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "AccountManagement.h"

int deposit(Account *account, long long amountCents);
int withdraw(Account *account, long long amountCents);
int transfer(Account *sender, Account *receiver, long long amountCents);

#endif
