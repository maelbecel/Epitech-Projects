/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include "my.h"
#include "printf.h"
#include <stdlib.h>

static const struct flag fonction[] = {
    {&dispstr, 's'},
    {&dispchar, 'c'},
    {&dispint, 'd'},
    {&dispint, 'i'},
    {&disppercent, '%'},
    {&dispunsigned, 'u'},
    {&dispbin, 'b'},
    {&dispoct, 'o'},
    {&disphexa, 'x'},
    {&disphexamaj, 'X'},
    {&disppointer, 'p'},
    {NULL, -1},
};

void display(char flag, va_list *arg)
{
    int i = 0;

    while (fonction[i].flag_f != -1) {
        if (fonction[i].flag_f == flag) {
            fonction[i].func(arg);
            break;
        }
        i++;
    }
}

void my_printf(char const *s, ...)
{
    va_list arg;
    int i = 0;

    va_start(arg, s);
    while (i < my_strlen(s)) {
        if (s[i] == '%') {
            display(s[i + 1], &arg);
            i++;
        } else {
            my_putchar(s[i]);
        }
        i++;
    }
    va_end(arg);
}
