/*
** EPITECH PROJECT, 2021
** intochar.C
** File description:
** int to char
*/

#include "my.h"
#include <stdlib.h>

int getlen(int num)
{
    int d = 0;

    if (num == 0){
        return 1;
    }
    while (num != 0) {
        num = num / 10;
        d++;
    }
    return d;
}

char *inttochar(int number)
{
    char *res = malloc(sizeof(char) * (getlen(number) + 1));
    int d = 0;

    if (number == 0){
        return "0";
    }
    while (number != 0) {
        res[d] = number % 10 + '0';
        number = number / 10;
        d++;
    }
    res[d] = '\0';
    return my_revstr(res);
}

