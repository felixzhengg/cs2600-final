#ifndef INPUT_H
#define INPUT_H

#include <stddef.h>

int readLine(const char *prompt, char buffer[], size_t size);
int readInteger(const char *prompt, int *value);
int readAmount(const char *prompt, long long *amountCents);

#endif
