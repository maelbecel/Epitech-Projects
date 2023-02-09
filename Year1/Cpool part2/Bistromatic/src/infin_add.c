/*
** EPITECH PROJECT, 2021
** infin_add.c
** File description:
** xxx
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

int charinarray (char x, char *base)
{
    for (int i = 0; base[i] != '\0'; i++){
        if (base[i] == x){
            return 1;
        }
    }
    return 0;
}

int getid(char c, char *base)
{

    for (int i = 0; base[i] != '\0'; i++){
        if (base[i] == c)
            return i;
    }
    return -1;
}

char *addretenue(char *str, int i, int retenue, char *base)
{
    if (retenue != 0){
        str[i] = base[retenue];
        str[i+1] =  '\0';
    }else
        str[i] = '\0';
    return str;
}

char *infinadd (char *calcul, char *base, char *baseop)
{
    int cal;
    int r = 0;
    int i = 0;
    char *res = malloc(my_strlen(calcul));
    char *nb1 = my_revstr(detection(calcul, base));
    char *op = detection(calcul + my_strlen(nb1), baseop);
    char *nb2 = my_revstr(
                detection(calcul + my_strlen(nb1) + my_strlen(op), base));
    while (i < my_strlen(nb1) || i < my_strlen(nb2)){
        if (i >= my_strlen(nb1))
            cal = getid(nb2[i], base) + r;
        else if (i >= my_strlen(nb2))
            cal = getid(nb1[i], base) + r;
        else
            cal = getid(nb1[i], base) + getid(nb2[i], base) + r;
        r = cal/my_strlen(base);
        res[i] = base[cal%my_strlen(base)];
        i++;
    }
    return my_revstr(addretenue(res, i, r, base));
}
