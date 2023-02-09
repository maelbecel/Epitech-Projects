/*
** EPITECH PROJECT, 2021
** removez.c
** File description:
** remove zero
*/

#include <my.h>

char *removez(char *str, char *base, char *baseop)
{
    int len = my_strlen(str)-1;
    char c;
    if (my_strlen(str) == 1)
        return str;
    if (str[len] == baseop[3]) {
        c = baseop[3];
        len--;
    } else
        c = '\0';
    while (str[len] == base[0])
        len--;
    if (len == my_strlen(str)-1)
        return str;
    else if (len == my_strlen(str)-2) {
        str[len + 1] = c;
        return str;
    } else {
        str[len + 1] = c;
        str[len + 2] = '\0';
        return str;
    }
}