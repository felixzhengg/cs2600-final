/*
Group 10
Aris Sarkisian, Ethan Caoile, Felix Zheng, Micah Kang, Ricky Paque
CS 2600
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[100];
    long long balanceCents;
} Account;

#endif
