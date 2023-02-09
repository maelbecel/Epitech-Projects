/*
** EPITECH PROJECT, 2021
** infinmod.c
** File description:
** infin modulo
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

int mod_neg(char *calcul, char *op, char *baseop)
{
    if (calcul[0] == baseop[3] && op[my_strlen(op) - 1] == baseop[3])
        return 1;
    else if (calcul[0] == baseop[3])
        return 2;
    return 0;
}

char *infinmod(char *calcul, char *base, char *baseop)
{
    char *temp = malloc(my_strlen(calcul)+1);
    char *nb1 = detection(calcul, base);
    char *op = detection(calcul + my_strlen(nb1), baseop);
    char *nb2 = detection(calcul + my_strlen(nb1) + my_strlen(op), base);
    int isneg = mod_neg(calcul, op, baseop);

    if (nb2 == base[0]){
        my_putstr(ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    if (isneg != 0)
        nb1 += 1;
    temp = infindiv(concat(nb1, "/", nb2), base, baseop);
    temp = infinmul(concat(temp, "*", nb2), base, baseop);
    temp = infinsub(concat(nb1, "-", temp), base, baseop);
    if (my_strlen(temp) < 1)
        return "0";
    if (isneg != 0)
        return concat("-", temp, "\0");
    return temp;
}