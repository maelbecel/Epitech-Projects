/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** xxx
*/

#include <stdlib.h>

int my_strlen(char * c);

char *my_strdup(char const *src)
{
    char *ret;
    int i = 0;

    ret = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != '\0') {
        ret[i] = src[i];
        i++;
    }
    ret[i] = '\0';
    return (ret);
}