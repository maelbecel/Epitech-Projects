/*
** EPITECH PROJECT, 2021
** displaychar.c
** File description:
** display char
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void displaychar(va_list argv)
{
    int c = va_arg(argv, int);
    my_putchar(c);
}
