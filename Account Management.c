#include <stdio.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[100];
    long long balanceCents;
} Account;

void createAccount(Account accounts[], int *count) {
    if (*count >= MAX_ACCOUNTS) {
        printf("Account limit reached.\n");
        return;
    }

    Account newAccount;

    newAccount.accountNumber = 1001 + *count;
    newAccount.balanceCents = 0;

    printf("Enter account holder's name: ");
    scanf(" %99[^\n]", newAccount.name);

    accounts[*count] = newAccount;
    (*count)++;

    printf("Account created! Account number: %d\n",
           newAccount.accountNumber);
}

void viewAccount(const Account accounts[], int count) {
    int number;

    printf("Enter account number: ");

    if (scanf("%d", &number) != 1) {
        int character;
        while ((character = getchar()) != '\n' && character != EOF) {
        }
        printf("Please enter a number.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == number) {
            printf("\nAccount number: %d\n", accounts[i].accountNumber);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: $%lld.%02lld\n",
                   accounts[i].balanceCents / 100,
                   accounts[i].balanceCents % 100);
            return;
        }
    }

    printf("Account not found.\n");
}

int main(void) {
    Account accounts[MAX_ACCOUNTS];
    int count = 0;
    int choice;

    do {
        printf("\n1. Create account\n");
        printf("2. View account\n");
        printf("3. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            int character;
            while ((character = getchar()) != '\n' && character != EOF) {
            }

            if (character == EOF) {
                break;
            }

            printf("Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                createAccount(accounts, &count);
                break;
            case 2:
                viewAccount(accounts, count);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (choice != 3);

    return 0;
}