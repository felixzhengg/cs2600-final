/*
Group 10
Aris Sarkisian, Ethan Caoile, Felix Zheng, Micah Kang, Ricky Paque
CS 2600
File: transactions.c
Contributor: Felix
*/

#include <stdio.h>
#include "AccountManagement.h"
#include "history.h"

/*
 * Deposits money into an account.
 * Returns 1 if successful and 0 if rejected.
 */
int deposit(Account *account, long long amountCents)
{
    if (account == NULL)
    {
        return 0;
    }

    if (amountCents <= 0)
    {
        return 0;
    }

    account->balanceCents = account->balanceCents + amountCents;

    /*
     * TODO: connect the transaction-history function here (Aris's part)
     */

    return 1;
}

/*
 * Withdraws money from an account.
 * Returns 1 if successful and 0 if rejected.
 */
int withdraw(Account *account, long long amountCents)
{
    if (account == NULL)
    {
        return 0;
    }

    if (amountCents <= 0)
    {
        return 0;
    }

    if (amountCents > account->balanceCents)
    {
        return 0;
    }

    account->balanceCents = account->balanceCents - amountCents;

    /*
     * TODO: connect the transaction-history function here (Aris's part)
     */

    return 1;
}

/*
 * Transfers money from one account to another.
 * Returns 1 if successful and 0 if rejected.
 */
int transfer(Account *sender, Account *receiver, long long amountCents)
{
    if (sender == NULL || receiver == NULL)
    {
        return 0;
    }

    if (sender == receiver)
    {
        return 0;
    }

    if (amountCents <= 0)
    {
        return 0;
    }

    if (amountCents > sender->balanceCents)
    {
        return 0;
    }

    sender->balanceCents = sender->balanceCents - amountCents;
    receiver->balanceCents = receiver->balanceCents + amountCents;

    /*
     * TODO: connect the transaction-history function here (Aris's part)
     */
    return 1;
}
