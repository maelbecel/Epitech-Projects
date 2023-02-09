/*
** EPITECH PROJECT, 2021
** print.h
** File description:
** print f
*/

#ifndef PRINTF_H_
#define PRINTF_H_

#include <stdarg.h>
#include <stddef.h>
// #include "my.h"

struct flags
{
    int(*func)(va_list argv);
    char flag;
};

int my_printf(char const *str, ...);

#endif
