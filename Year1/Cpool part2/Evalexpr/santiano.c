/*
** EPITECH PROJECT, 2021
** santiano.c
** File description:
** x
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char *concatv2(char *s1, char *s2)
{
    char *res = malloc(my_strlen(s1) + my_strlen(s2) + 1);
    int i = 0;
    int j = 0;

    while (s1[j] != '\0') {
        res[i] = s1[j];
        j++;
        i++;
    }
    j = 0;
    while (s2[j] != '\0') {
        res[i] = s2[j];
        i++;
        j++;
    }
    res[i] = '\0';
    return res;
}

int lencalcul(char *str)
{
    int len = 0;
    len = my_intstrlen(str);
    len++;
    len += my_intstrlen(str + len);
    return len;
}

int santiano(char *str)
{
    char *result = malloc(sizeof(char) * 11);

    while (my_str_isnum(str) == 0) {
        result = inttochar(detection(str));
        str = concatv2(result, str + lencalcul(str));
    }
    return my_getnbr(result);
}
