/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** my swap
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}
