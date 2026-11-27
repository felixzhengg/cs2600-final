/*
Group 10
Aris Sarkisian, Ethan Caoile, Felix Zheng, Micah Kang, Ricky Paque
CS2600
*/
#include <stdio.h>
#include "AccountManagement.h"
#include "transactions.h"
#include "file_management.h"
#include "history.h"
#include "input.h"

static int selectAccount(const Account accounts[], int count,
                         const char *prompt)
{
    int number;
    if (readInteger(prompt, &number) != 1) {
        return -1;
    }
    int index = findAccount(accounts, count, number);
    if (index == -1) {
        printf("Account not found.\n");
    }
    return index;
}

static void accountMenu(Account accounts[], int *count)
{
    for (;;) {
        int choice;
        printf("\n1. Create account\n2. View account\n3. Back\n");
        int result = readInteger("Option: ", &choice);
        if (result == -1) {
            return;
        }
        if (result == 0) {
            continue;
        }
        switch (choice) {
            case 1:
                if (createAccount(accounts, count)) {
                    saveAccounts(accounts, *count);
                }
                break;
            case 2:
                viewAccount(accounts, *count);
                break;
            case 3:
                return;
            default:
                printf("Not an option.\n");
        }
    }
}

static void transactionMenu(Account accounts[], int count, int choice)
{
    int index = selectAccount(accounts, count, "Enter account number: ");
    if (index == -1) {
        return;
    }
    int receiver = -1;
    if (choice == 5) {
        receiver = selectAccount(accounts, count,
                                 "Enter receiving account number: ");
        if (receiver == -1) {
            return;
        }
    }
    long long amountCents;
    if (readAmount("Enter amount in dollars (example 25.50): ",
                   &amountCents) != 1) {
        return;
    }
    int success = 0;
    if (choice == 2) {
        success = deposit(&accounts[index], amountCents);
    } else if (choice == 3) {
        success = withdraw(&accounts[index], amountCents);
    } else if (choice == 5) {
        success = transfer(&accounts[index], &accounts[receiver], amountCents);
    }
    if (success) {
        saveAccounts(accounts, count);
        printf("Transaction completed.\n");
    } else {
        printf("Transaction rejected. Check the balance, amount, and accounts.\n");
    }
}

int main(void)
{
    Account accounts[MAX_ACCOUNTS];
    int count = loadAccounts(accounts);
    printf("Welcome to the Banking Simulator\n");
    printf("Loaded %d account(s).\n", count);
    for (;;) {
        int choice;
        printf("\n1. Account\n2. Deposit\n3. Withdraw\n4. Quit\n");
        printf("5. Transfer\n6. Transaction history\n");
        int result = readInteger("Option: ", &choice);
        if (result == -1 || (result == 1 && choice == 4)) {
            printf("Goodbye!\n");
            break;
        }
        if (result == 0) {
            continue;
        }
        switch (choice) {
            case 1:
                accountMenu(accounts, &count);
                break;
            case 2:
            case 3:
            case 5:
                transactionMenu(accounts, count, choice);
                break;
            case 6: {
                int index = selectAccount(accounts, count,
                                          "Enter account number: ");
                if (index != -1) {
                    viewHistory(accounts[index].accountNumber);
                }
                break;
            }
            default:
                printf("Not an option.\n");
        }
    }
    return 0;
}
