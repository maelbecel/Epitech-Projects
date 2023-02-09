/*
** EPITECH PROJECT, 2021
** concat.c
** File description:
** concat 3 char *
*/

#include <stdlib.h>

int my_strlen(char *c);

char *concat(char *before, char *mid, char *after)
{
    char *res = malloc(my_strlen(after) +
        my_strlen(mid) +
        my_strlen(before) + 2);
    int i = 0;

    for (int j = 0; before[j] != '\0'; j++){
        res[i] = before[j];
        i++;
    }
    for (int j = 0; mid[j] != '\0'; j++){
        res[i] = mid[j];
        i++;
    }
    for (int j = 0; after[j] != '\0'; j++){
        res[i] = after[j];
        i++;
    }
    res[i] = '\0';
    return res;
}
