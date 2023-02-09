/*
** EPITECH PROJECT, 2021
** infindiv.c
** File description:
** infin division
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

void checkdiv(char *nb2, char *base)
{
    if (nb2 == "" || nb2[0] == base[0]){
        my_putstr(ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
}

char *negdiv(char *nb, char c, char op)
{
    if (c == op)
        return nb + 1;
    return nb;
}

char *infindiv(char *calcul, char *base, char *baseop)
{
    char *nb1 = detection(calcul, base);
    char *op = detection(calcul + my_strlen(nb1), baseop);
    char *nb2 = detection(calcul + my_strlen(nb1) + my_strlen(op), base);
    char *cal = malloc(my_strlen(calcul)+1);
    char *i = malloc(my_strlen(calcul)+1);
    int isneg = isnegative(calcul, op, baseop);

    cal[0] = '0';
    i[0] = '0';
    nb1 = negdiv(nb1, calcul[0], baseop[3]);
    checkdiv(nb2, base);
    if (infinsub(concat(nb1, "-", nb2), base, baseop)[0] == baseop[3])
        return "0";
    while (infinsub(concat(nb1, "-", cal), base, baseop)[0] != baseop[3]) {
        cal = infinmul(concat(nb2, "*", i), base, baseop);
        i = infinadd(concat(i, "+", "1"), base, baseop);
    }
    if (isneg != 0)
        return concat("-", infinsub(concat(i, "-", "2"), base, baseop), "\0");
    return infinsub(concat(i, "-", "2"), base, baseop);
}