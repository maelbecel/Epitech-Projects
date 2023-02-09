/*
** EPITECH PROJECT, 2021
** displaypercent.c
** File description:
** display percent
*/

#include <stdarg.h>

void my_putchar(char c);

int displaypercent(__attribute__((unused))va_list argv)
{
    my_putchar('%');
    return 0;
}
