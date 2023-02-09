/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** my swap
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}

int my_printarray(char **array, char sep)
{
    while (*array){
        my_putstr(*array++);
        if (*array)
            write(1, &sep, 1);
    }
}
