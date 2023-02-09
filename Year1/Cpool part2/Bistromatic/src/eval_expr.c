/*
** EPITECH PROJECT, 2021
** eval_expr.c
** File description:
** eval_expr.c
*/

#include "my.h"
#include "bistromatic.h"
#include <stdlib.h>

int number(char **str)
{
    int negative = 1;
    int nbr = 0;
    if ((*str)[0] == '+' || (*str)[0] == '-') {
        if ((*str)[0] == '-')
            negative = -1;
        (*str)++;
    }
    if ((*str)[0] == '(') {
        (*str)++;
        nbr = priorities(str);
        if ((*str)[0] == ')')
            (*str)++;
        return (nbr * negative);
    }
    while ((*str)[0] >= '0' && (*str)[0] <= '9') {
        nbr = (nbr * 10) + ((*str)[0] - '0');
        (*str)++;
    }
    return (nbr * negative);
}

int priorities(char **str)
{
    int a = number(str);
    int b;
    char op;

    while ((*str)[0] != 0 && (*str)[0] != ')') {
        op = (*str)[0];
        (*str)++;
        b = ((op == '+' || op == '-')
                ? factors(str) : number(str));
        a = classic_op(a, b, op);
    }
    return (a);
}

int factors(char **str)
{
    int nbr = number(str);
    char op;

    while ((*str)[0] == '*' || (*str)[0] == '/' || (*str)[0] == '%') {
        op = (*str)[0];
        (*str)++;
        nbr = classic_op(nbr, number(str), op);
    }
    return (nbr);
}

int eval_expr(char *str)
{
    if (str[0] == 0)
        return (0);
    return (priorities(&str));
}
