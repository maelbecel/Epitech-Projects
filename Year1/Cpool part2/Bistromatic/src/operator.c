/*
** EPITECH PROJECT, 2021
** operator.c
** File description:
** switch from op
*/

#include <my.h>
#include "bistromatic.h"
#include <stdlib.h>

char addorsub(char *op, char *baseop)
{
    int nbmoins = 0;

    if (getid(op[0], baseop) != 2 && getid(op[0], baseop) != 3)
        return op[0];
    for (int i = 0; (getid(op[i], baseop) == 2 ||
        getid(op[i], baseop) == 3 ) &&
        op[i] != '\0'; i++){
        if (getid(op[i], baseop) == 3)
            nbmoins++;
    }
    if (nbmoins%2 == 0)
        return baseop[2];
    return baseop[3];
}

int operator(char *expr, char *base, char *baseop)
{
    char *op = detection(expr + my_strlen(detection(expr, base)), baseop);
    switch (getid(addorsub(op, baseop), baseop)) {
        case 2:
            my_putstr(infinadd(expr, base, baseop));
            return 0;
        case 3:
            my_putstr(infinsub(expr, base, baseop));
            return 0;
        case 4:
            my_putstr(infinmul(expr, base, baseop));
            return 0;
        case 5:
            my_putstr(infindiv(expr, base, baseop));
            return 0;
        case 6:
            my_putstr(infinmod(expr, base, baseop));
            return 0;
    }
    my_putstr(SYNTAX_ERROR_MSG);
    exit(EXIT_OPS);
}
