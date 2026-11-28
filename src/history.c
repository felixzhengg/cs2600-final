
/*
Group 10
Aris Sarkisian, Ethan Caoile, Felix Zheng, Micah Kang, Ricky Paque
CS 2600
File: history.c
Contributor: Aris
*/

#include <stdio.h>
#include "history.h"

/*
 * Records a transaction into transactions.txt.
 * Returns 1 if successful, 0 if unsuccessful.
 */
int recordTransaction(int accountNumber,
                      const char *type,
                      long long amountCents,
                      long long balanceCents)
{
    FILE *file = fopen("transactions.txt", "a");

    if (file == NULL)
    {
        perror("Error opening transaction file");
        return 0;
    }

    if (fprintf(file, "%d %s %lld %lld\n",
                accountNumber, type,
                amountCents, balanceCents) < 0)
    {
        fclose(file);
        return 0;
    }

    if (fclose(file) != 0)
    {
        return 0;
    }

    return 1;
}

/*
 * Displays the transaction history of an account.
 */
void viewHistory(int accountNumber)
{
    FILE *file = fopen("transactions.txt", "r");

    if (file == NULL)
    {
        printf("No transaction history found.\n");
        return;
    }

    int id;
    char type[30];
    long long amountCents;
    long long balanceCents;
    int count = 0;

    printf("\n===== TRANSACTION HISTORY =====\n");
    printf("Account Number: %d\n\n", accountNumber);

    printf("%-16s %-12s %-12s\n",
           "Type", "Amount", "Balance");
    printf("------------------------------------------\n");

    while (fscanf(file, "%d %29s %lld %lld",
                  &id, type,
                  &amountCents, &balanceCents) == 4)
    {
        if (id == accountNumber)
        {
            printf("%-16s $%-11.2f $%.2f\n",
                   type,
                   amountCents / 100.0,
                   balanceCents / 100.0);

            count++;
        }
    }

    if (count == 0)
    {
        printf("No transactions found for this account.\n");
    }

    printf("\nTotal Transactions: %d\n", count);

    fclose(file);
}
