/*
** EPITECH PROJECT, 2021
** infin_add.c
** File description:
** xxx
*/

#include <stdlib.h>
#include "bistromatic.h"
#include <my.h>

int upperthan(char *a, char *b, char *calcul, char *baseop)
{
    int i = 0;

    if (calcul[0] == baseop[3])
        return -1;
    if (my_strlen(a) > my_strlen(b))
        return 1;
    else if (my_strlen(a) < my_strlen(b))
        return 0;
    else {
        while ((a[i] == b[i]) && a[i] != '\0') {
            i++;
        }
    }
    if (a[i] == b[i])
        return 0;
    else if (a[i] > b[i])
        return 1;
    else
        return 0;
}

char *infinsub(char *calcul, char *base, char *baseop)
{
    int lenbase = my_strlen(base);
    int cal;
    int r = 0;
    int i = 0;
    int isneg = 0;
    char *res = malloc(my_strlen(calcul));
    char *nb1 = my_revstr(detection(calcul, base));
    char *op = detection(calcul + my_strlen(nb1), baseop);
    char *nb2 = my_revstr(
                detection(calcul + my_strlen(nb1) + my_strlen(op), base));

    if (upperthan(my_revstr(nb2), my_revstr(nb1), calcul, baseop) == 1) {
        isneg = 1;
        nb2 = my_revstr(nb1);
        nb1 = my_revstr(
                detection(calcul + my_strlen(nb1) + my_strlen(op), base));
    }else if (upperthan(my_revstr(nb2), my_revstr(nb1), calcul, baseop) == -1){
        res[0] = baseop[3];
        res = my_strcat(res, infinadd(calcul+1, base, baseop));
        return res;
    }

    while (i < my_strlen(nb1) || i < my_strlen(nb2)) {
        if (i >= my_strlen(nb1))
            cal = 0 - (getid(nb2[i], base) + r);
        else if (i >= my_strlen(nb2))
            cal = getid(nb1[i], base) - r;
        else
            cal = getid(nb1[i], base) - (getid(nb2[i], base) + r);
        if (cal < 0){
            r = 1;
            res[i] = base[lenbase + cal];
        } else {
            r = 0;
            res[i] = base[cal];
        }
        i++;
    }
    if (isneg == 1) {
        res[i] = baseop[3];
        i++;
    }
    res[i] = '\0';
    if ((getid(res[i - 1], base) == 0) && res[i-1] != baseop[3])
        res[i-1] = '\0';
    if (res[0] == 0)
        return base[0];
    res = removez(res, base, baseop);
    return my_revstr(res);
}
