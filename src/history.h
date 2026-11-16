
/*
Group 10
Aris Sarkisian, Ethan Caoile, Felix Zheng, Micah Kang, Ricky Paque
CS 2600
File: history.h
Contributor: Aris
*/

#ifndef HISTORY_H
#define HISTORY_H

int recordTransaction(int accountNumber,
                      const char *type,
                      long long amountCents,
                      long long balanceCents);

void viewHistory(int accountNumber);

#endif
