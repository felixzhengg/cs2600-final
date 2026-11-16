/*
Group 10
Aris Sarkisian, Ethan Caoile, Felix Zheng, Micah Kang, Ricky Paque
CS 2600
*/

#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

#include <stdbool.h>
#include "AccountManagement.h"

void saveAccounts(const Account accounts[], int count);

int loadAccounts(Account accounts[]);

bool HasAccount(Account *account);

#endif
