/*
Group 10
Aris Sarkisian, Ethan Caoile, Felix Zheng, Micah Kang, Ricky Paque
CS 2600
File: transactions.c
Contributor: Felix
*/

#include <stdio.h>

struct Account
{
    int accountID;
    char name[50];
    double balance;
};

/*
 * Deposits money into an account.
 * Returns 1 if successful and 0 if rejected.
 */
int deposit(struct Account *account, double amount)
{
    if (account == NULL)
    {
        return 0;
    }

    if (amount <= 0)
    {
        return 0;
    }

    account->balance = account->balance + amount;

    /*
     * TODO: connect the transaction-history function here (Aris's part)
     */

    return 1;
}

/*
 * Withdraws money from an account.
 * Returns 1 if successful and 0 if rejected.
 */
int withdraw(struct Account *account, double amount)
{
    if (account == NULL)
    {
        return 0;
    }

    if (amount <= 0)
    {
        return 0;
    }

    if (amount > account->balance)
    {
        return 0;
    }

    account->balance = account->balance - amount;

    /*
     * TODO: connect the transaction-history function here (Aris's part)
     */

    return 1;
}

/*
 * Transfers money from one account to another.
 * Returns 1 if successful and 0 if rejected.
 */
int transfer(struct Account *sender,
             struct Account *receiver,
             double amount)
{
    if (sender == NULL || receiver == NULL)
    {
        return 0;
    }

    if (sender == receiver)
    {
        return 0;
    }

    if (amount <= 0)
    {
        return 0;
    }

    if (amount > sender->balance)
    {
        return 0;
    }

    sender->balance = sender->balance - amount;
    receiver->balance = receiver->balance + amount;

    /*
     * TODO: connect the transaction-history function here (Aris's part)
     */
    return 1;
}

/*
 * Temporary testing main
 *
 * TODO: Remove this main function when the group combines this file with the rest of the project.
 */
int main(void)
{
    struct Account felix = {1001, "Felix", 500.00};
    struct Account joe = {1002, "Joe", 200.00};

    printf("Starting balances:\n");
    printf("Felix: %.2f\n", felix.balance);
    printf("Joe: %.2f\n\n", joe.balance);

    if (deposit(&felix, 100.00))
    {
        printf("Deposit successful.\n");
    }
    else
    {
        printf("Deposit rejected.\n");
    }

    if (withdraw(&felix, 50.00))
    {
        printf("Withdrawal successful.\n");
    }
    else
    {
        printf("Withdrawal rejected.\n");
    }

    if (transfer(&felix, &joe, 150.00))
    {
        printf("Transfer successful.\n");
    }
    else
    {
        printf("Transfer rejected.\n");
    }

    if (withdraw(&felix, 1000.00))
    {
        printf("Invalid withdrawal accepted.\n");
    }
    else
    {
        printf("Withdrawal rejected because of insufficient funds.\n");
    }

    printf("\nEnding balances:\n");
    printf("Felix: %.2f\n", felix.balance);
    printf("Joe: %.2f\n", joe.balance);

    return 0;
}
