/*
** EPITECH PROJECT, 2021
** eval_expr.c
** File description:
** evalex
*/

#include "my.h"
#include <stdlib.h>

int havebracket(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            return 1;
    }
    return 0;
}

char *getbracket(char *av)
{
    char *cal = malloc(sizeof(int) * 2 +1);
    int bracket = 1;
    int i = 0;
    int j = 0;

    while (av[i] != '('){
        i++;
    }
    i++;
    while (bracket != 0){
        if (av[i] == '(')
            bracket++;
        else if (av[i] == ')')
            bracket--;
        cal[j] = av[i];
        j++;
        i++;
    }
    cal[j-1] = '\0';
    return cal;
}

char *concat(char *before, char *mid, char *after)
{
    char *res = malloc(my_strlen(after) +
        my_strlen(mid) +
        my_strlen(before) + 1);
    int i = 0;

    for (int j = 0; before[j] != '\0'; j++){
        res[i] = before[j];
        i++;
    }
    for (int j = 0; mid[j] != '\0'; j++){
        res[i] = mid[j];
        i++;
    }
    for (int j = 0; after[j] != '\0'; j++){
        res[i] = after[j];
        i++;
    }
    res[i] = '\0';
    return res;
}

char *replace(char *calc, char *av)
{
    char *before = my_strstart(av, calc);
    char *mid = inttochar(santiano(calc));
    char *after = my_strstr(av, calc) + my_strlen(calc) + 1;

    return concat(before, mid, after);
}

int eval_expr(char *str)
{
    char *av = str;
    char *bra;
    char *par = delpar(str);
    if (par[0] == '-')
        if (my_str_isnum(par+1) == 1)
            return my_getnbr(par);
    if (my_str_isnum(par) == 1)
        return my_getnbr(par);

    while (havebracket(av)){
        bra = av;
        while (havebracket(bra)){
            bra = getbracket(bra);
        }
        av = replace(bra, av);
    }
    if (nbop(av) > 1)
        return santiano(tri(listop(av)));
   	else {
        return detection(av);
    }
}
