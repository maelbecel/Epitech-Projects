/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** my swap
*/

#include <unistd.h>

int my_strlen(char *str);

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
    return 0;
}
