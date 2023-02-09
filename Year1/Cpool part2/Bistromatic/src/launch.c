/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** Bistro
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromatic.h"
#include "my.h"
#include <stdio.h>

int my_putstr(char const *);
int my_strlen(char const *);

int same(int i, int j, char const *base, int n)
{
    if (base[i] == base[j])
        return n+1;
    return n;
}

static void check_ops(char const *ops)
{
    int nb = 0;
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
    for (int i = 0; ops[i] != '\0'; i++){
        for (int j = 0; ops[j] != '\0'; j++)
            nb = same(i, j, ops, nb);
        if (nb > 1){
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_OPS);
        }
        nb = 0;
    }
}

static void check_base(char const *b)
{
    int nb = 0;
    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
    for (int i = 0; b[i] != '\0'; i++){
        for (int j = 0; b[j] != '\0'; j++)
            nb = same(i, j, b, nb);
        if (nb > 1){
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_BASE);
        }
        nb = 0;
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (ac != 4) {
        usage(av);
        my_putstr(SYNTAX_ERROR_MSG);
        return (EXIT_READ);
        }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    if (nbnumber(expr, av[1], av[2]) > 2){
        my_put_nbr(eval_expr(expr));
        return (EXIT_SUCCESS);
    }
    error_in_av(expr, av[1], av[2], size);
    operator(expr, av[1], av[2]);
    return (EXIT_SUCCESS);
}
