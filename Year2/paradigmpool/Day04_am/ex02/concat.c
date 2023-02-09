/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "concat.h"
#include <stdlib.h>

void concat_strings(const char *str1, const char *str2 , char **res)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = 0;
    int j = 0;

    *res = malloc(sizeof(char) * (len1 + len2 + 1));
    while (i < len1) {
        (*res)[i] = str1[i];
        i++;
    }
    while (j < len2) {
        (*res)[i] = str2[j];
        i++;
        j++;
    }
    (*res)[i] = '\0';
}

void concat_struct(concat_t *str)
{
    int len1 = strlen(str->str1);
    int len2 = strlen(str->str2);
    int i = 0;
    int j = 0;

    str->res = malloc(sizeof(char) * (len1 + len2 + 1));
    while (i < len1) {
        str->res[i] = str->str1[i];
        i++;
    }
    while (j < len2) {
        str->res[i] = str->str2[j];
        i++;
        j++;
    }
    str->res[i] = '\0';
}
