/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** my swap
*/

#include <stdio.h>

void my_putchar(char c);

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}
