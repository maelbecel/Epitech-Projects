/*
** EPITECH PROJECT, 2021
** displaychar.c
** File description:
** display char
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "my.h"

int my_strlen(char const *str);

void displaystr(va_list argv)
{
    char *str = va_arg(argv, char*);
    write(1, str, my_strlen(str));
}
