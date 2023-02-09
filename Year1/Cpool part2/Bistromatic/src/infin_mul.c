/*
** EPITECH PROJECT, 2021
** infinmul.c
** File description:
** infin multiplication
*/

#include <stdlib.h>
#include "bistromatic.h"
#include <my.h>

char *neg(char *res, int isneg)
{
    if (isneg != 0)
        res = concat("-", res, "\0");
    return res;
}

char *adaptneg(char *str, int i, int isneg)
{
    if (isneg == 1)
        return '\0';
    return str[i];
}

int isnegative(char *calcul, char *op, char *baseop)
{
    if (calcul[0] == baseop[3]){
        if (op[my_strlen(op) - 1] == baseop[3])
            return 0;
        else
            return 1;
    } else if (op[my_strlen(op) - 1] == baseop[3])
        return 2;
    return 0;
}

char *infinmul(char *calcul, char *base, char *baseop)
{
    int x = 1, y = 1;
    char *cal;
    char *res = malloc(my_strlen(calcul));
    char *nb1 = my_revstr(detection(calcul, base));
    int isneg = isnegative(calcul,
                detection(calcul + my_strlen(nb1), baseop), baseop);
    char *nb2 = my_revstr(detection(calcul + my_strlen(nb1) +
                my_strlen(detection(calcul + my_strlen(nb1), baseop)), base));
    nb1[my_strlen(nb1) - 1] = adaptneg(nb1, my_strlen(nb1) - 1, isneg);
    res[0] = base[0];
    for (int i = 0; nb1[i] != '\0'; i++){
        for (int j = 0; nb2[j] != '\0'; j++){
            cal = concat(res, "+", inttochar(
                getid(nb2[j], base)*y*getid(nb1[i], base)*x));
            res = infinadd(cal, base, baseop);
            y *= 10;
        }
        x *= (y = 1) * 10;
    }
    return neg(res, isneg);
}
