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


int main()
{
  printf("Welcome to the Banking Simulator\nBy Ethan Caoile, Micah Kang, Ricky Paque, Aris Sarkisian, and Felix Zheng\n");
  int quit = 0; 
  printf("Select Option:\n");
  printf("1. Account\n");
  printf("2. Deposit\n");
  printf("3. Withdraw\n");
  printf("4. Quit\n");
  while(!quit){
    int x = 0;
    
    printf("Option: ");
    if(scanf("%d", &x) != 1){
      printf("Error, input integer value\n");
      while(getchar() != '\n');
      continue;
    }

    if(x == 1){
      printf("Select 1 to create account\nSelect 2 if already have one\nOption:");
      int z = 0;
      if(scanf("%d", &z) != 1){
		printf("Error, non int inputted, returning to main menu\n");
		while(getchar() != '\n');
		continue;
      }
      if(z ==1){
		printf("New Account\n");
      } else if(z == 2){
		printf("Old Account\n");
      } else {
		printf("Not an option, returning to main menu\n");
      }
    } else if(x == 2){
      printf("Deposit\n");
    } else if(x == 3){
      printf("Withdraw\n");
    } else if(x == 4){
      printf("Quitting\n");
      quit = 1;
    } else{
      printf("Not an option\n");
    }
  }
  return 0;
}
