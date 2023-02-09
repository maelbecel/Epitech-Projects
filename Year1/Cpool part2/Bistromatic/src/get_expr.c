/*
** EPITECH PROJECT, 2021
** get_expr.c
** File description:
** get expression
*/

#include "bistromatic.h"
#include "my.h"
#include <stdlib.h>
#include <unistd.h>

char  *get_expr(int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}