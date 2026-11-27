#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "AccountManagement.h"

int deposit(Account *account, long long amountCents);
int withdraw(Account *account, long long amountCents);
int transfer(Account *sender, Account *receiver, long long amountCents);

#endif
