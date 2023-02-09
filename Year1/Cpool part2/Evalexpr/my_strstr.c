/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** strstrx
*/

#include "my.h"
#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int size = my_strlen(to_find);
    int result = 1;

    while (str[i] != '\0') {
        if (str[i] == to_find[0])
            result = my_strncmp(str + i, to_find, size);
        if (result == 0)
            return (str + i);
        i++;
    }
    return NULL;
}
