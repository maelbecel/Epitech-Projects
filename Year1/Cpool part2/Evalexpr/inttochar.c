/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** x
*/

#include "my.h"
#include <stdlib.h>

char *inttochar(int num)
{
    char *res = malloc(num);
    int mod = 100;
    int division = 10;
    int i = 1;

    res[0] = num % 10 + 48;
    while (division <= num) {
        res[i] = ((num % mod) / division) + 48;
        i += 1;
        division *= 10;
        mod *= 10;
    }
    if (num < 0){
        res[i] == '-';
        i++;
    }
    res[i] = '\0';
    res = my_revstr(res);
    return res;
}
