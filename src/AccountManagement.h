#ifndef ACCOUNT_H
#define ACCOUNT_H

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[100];
    long long balanceCents;
} Account;

#endif