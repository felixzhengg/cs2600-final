/* 
Group 10
Aris Sarkisian, Ethan Caoile, Felix Zheng, Micah Kang, Ricky Paque 
CS 2600
*/
// Contributor: Ethan Caoile
#include <stdio.h>
#include <stdbool.h>
#include "AccountManagement.h"

// file management: save and load account information from files

// save every account made in accounts array
void saveAccounts(const Account accounts[], int count)
{
    // open accounts.txt file for writing
    FILE *file = fopen("accounts.txt", "w");

    // case if file does not exist
    if (file == NULL){
        printf("File does not exist, try again.\n");
        return;
    }

    // loop through each account and write to accounts.txt
    for (int i = 0; i < count; i++){
        fprintf(file, "User %d:\n", i + 1);
        fprintf(file, "Account Number: %d\n", accounts[i].accountNumber);
        fprintf(file, "Name of user: %s\n", accounts[i].name);
        fprintf(file, "User balance: %lld\n", accounts[i].balanceCents);
        fprintf(file, "\n");
    }

    fclose(file);
}

// loads saved accounts from accounts.txt into the accounts array.
int loadAccounts(Account accounts[])
{
    Account temporaryAccount;   // store current account
    int count = 0;  // keep track of how many accs loaded

    // open accounts.txt for reading
    FILE *file = fopen("accounts.txt", "r");

    // check if file opened
    if (file == NULL) {
    return 0;
    }

    // read accs until the array is full or reading fails.
    while (count < MAX_ACCOUNTS) {
    
        int result; // store how many account fields successfully read for current acc

        result = fscanf(file,
                "User %*d:\n"
                "Account Number: %d\n"
                "Name of user: %99[^\n]\n"
                "User balance: %lld",
                &temporaryAccount.accountNumber,
                temporaryAccount.name,
                &temporaryAccount.balanceCents);

        // stop loop if reading failed
        if (result != 3) {
            break;
        }
    
        // store temporary acc in accounts array
        accounts[count] = temporaryAccount;

        count++;
    }

    fclose(file);

    // return num of accs loaded
    return count;
}

// edge cases ie if account does not exist
bool HasAccount(Account *account){
    if (account == NULL){
        return false;
    }
    return true;
}

// add this in beginning of main
// count = loadAccounts(accounts);