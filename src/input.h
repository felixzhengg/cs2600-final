/*
Group 10
Aris Sarkisian, Ethan Caoile, Felix Zheng, Micah Kang, Ricky Paque
CS 2600
*/
#ifndef INPUT_H
#define INPUT_H

#include <stddef.h>

int readLine(const char *prompt, char buffer[], size_t size);
int readInteger(const char *prompt, int *value);
int readAmount(const char *prompt, long long *amountCents);

#endif
