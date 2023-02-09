/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** strstrx
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

char nextbracket(int i, char *str)
{
    int x = i +1;
    while (str[x] != '\0'){
        if (str[x] == '(')
            return '(';
        else if (str[x] == ')')
            return ')';
        x++;
    }
}

char *my_strstart(char *str, char const *to_find)
{
    char *res = malloc(my_strlen(str));
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] == '(' && nextbracket(i, str) == ')')
            return res;
        else{
            res[i] = str[i];
            i++;
        }
    }
    return res;
}
