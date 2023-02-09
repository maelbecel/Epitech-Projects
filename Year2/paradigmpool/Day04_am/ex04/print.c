/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include <stdio.h>
#include "print.h"
#include <stdlib.h>
#include <string.h>’

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
}

void print_upper(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            printf("%c", str[i] - 32);
        else
            printf("%c", str[i]);
    }
    printf("\n");
}

void print_42( __attribute__((unused)) const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*ptr[4])(const char *) = {
        print_normal,
        print_reverse,
        print_upper,
        print_42
    };
    ptr[action](str);
}
