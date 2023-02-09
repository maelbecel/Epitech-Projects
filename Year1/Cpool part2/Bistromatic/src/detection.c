/*
** EPITECH PROJECT, 2021
** detection.c
** File description:
** detection
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

char *detection(char *calcul, char *base)
{
    char *res = malloc(my_strlen(calcul));
    int i = 0;

    if (calcul[i] == '-'){
        res[0] = '-';
        i++;
    }
    while (charinarray(calcul[i], base)){
        res[i] = calcul[i];
        i++;
    }
    return res;
}