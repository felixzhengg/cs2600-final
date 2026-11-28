/*
Group 10
Aris Sarkisian, Ethan Caoile, Felix Zheng, Micah Kang, Ricky Paque
CS 2600
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include "input.h"

int readLine(const char *prompt, char buffer[], size_t size)
{
    printf("%s", prompt);
    fflush(stdout);
    if (fgets(buffer, (int)size, stdin) == NULL) {
        return -1;
    }
    if (strchr(buffer, '\n') == NULL) {
        int ch = getchar();
        if (ch != '\n' && ch != EOF) {
            while ((ch = getchar()) != '\n' && ch != EOF) {
            }
            printf("Input is too long.\n");
            return 0;
        }
    }
    size_t length = strlen(buffer);
    while (length > 0 && isspace((unsigned char)buffer[length - 1])) {
        buffer[--length] = '\0';
    }
    size_t start = 0;
    while (isspace((unsigned char)buffer[start])) {
        start++;
    }
    memmove(buffer, buffer + start, length - start + 1);
    return 1;
}

int readInteger(const char *prompt, int *value)
{
    char line[100];
    int result = readLine(prompt, line, sizeof(line));
    if (result != 1) {
        return result;
    }
    char *end;
    errno = 0;
    long number = strtol(line, &end, 10);
    if (errno == ERANGE || end == line || *end != '\0' ||
        number < INT_MIN || number > INT_MAX) {
        printf("Please enter a whole number.\n");
        return 0;
    }
    *value = (int)number;
    return 1;
}

int readAmount(const char *prompt, long long *amountCents)
{
    char line[100];
    int result = readLine(prompt, line, sizeof(line));
    if (result != 1) {
        return result;
    }
    const char *cursor = line;
    long long dollars = 0;
    int digits = 0;
    while (isdigit((unsigned char)*cursor)) {
        int digit = *cursor++ - '0';
        if (dollars > (LLONG_MAX / 100 - digit) / 10) {
            printf("Amount is too large.\n");
            return 0;
        }
        dollars = dollars * 10 + digit;
        digits++;
    }
    int cents = 0;
    if (*cursor == '.') {
        cursor++;
        if (!isdigit((unsigned char)*cursor)) {
            printf("Enter an amount such as 25.50.\n");
            return 0;
        }
        cents = (*cursor++ - '0') * 10;
        if (isdigit((unsigned char)*cursor)) {
            cents += *cursor++ - '0';
        }
    }
    if (digits == 0 || *cursor != '\0' ||
        dollars > (LLONG_MAX - cents) / 100) {
        printf("Enter a positive amount with at most two decimal places.\n");
        return 0;
    }
    *amountCents = dollars * 100 + cents;
    if (*amountCents == 0) {
        printf("Amount must be greater than zero.\n");
        return 0;
    }
    return 1;
}
