/* 
Group 10
Aris Sarkisian, Ethan Caoile, Felix Zheng, Micah Kang, Ricky Paque 
CS 2600
*/
#include <stdio.h>
#include <limits.h>
#include "AccountManagement.h"
#include "input.h"

int findAccount(const Account accounts[], int count, int accountNumber)
{
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}

int createAccount(Account accounts[], int *count)
{
    if (*count >= MAX_ACCOUNTS) {
        printf("Account limit reached.\n");
        return 0;
    }
    int highestNumber = 1000;
    for (int i = 0; i < *count; i++) {
        if (accounts[i].accountNumber > highestNumber) {
            highestNumber = accounts[i].accountNumber;
        }
    }
    if (highestNumber == INT_MAX) {
        printf("No more account numbers are available.\n");
        return 0;
    }
    Account account;
    if (readLine("Enter account holder's name: ", account.name,
                 sizeof(account.name)) != 1) {
        return 0;
    }
    if (account.name[0] == '\0') {
        printf("Name cannot be blank.\n");
        return 0;
    }
    account.accountNumber = highestNumber + 1;
    account.balanceCents = 0;
    accounts[*count] = account;
    (*count)++;
    printf("Account created! Account number: %d\n", account.accountNumber);
    return 1;
}

void viewAccount(const Account accounts[], int count)
{
    int number;
    if (readInteger("Enter account number: ", &number) != 1) {
        return;
    }
    int index = findAccount(accounts, count, number);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }
    printf("\nAccount number: %d\n", accounts[index].accountNumber);
    printf("Name: %s\n", accounts[index].name);
    printf("Balance: $%lld.%02lld\n", accounts[index].balanceCents / 100,
           accounts[index].balanceCents % 100);
}
