/*
** EPITECH PROJECT, 2021
** error.c
** File description:
** fix error
*/

#include "my.h"
#include "bistromatic.h"
#include <stdlib.h>

void manyops(char *calcul, char *base, char *baseop)
{
    char *nb1 = detection(calcul, base);
    char *op = detection(calcul + my_strlen(nb1), baseop);

    for (int i = 1; op[i] != '\0'; i++){
        if (op[i] != baseop[3] && op[i] != baseop[2]){
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_OPS);
        }
    }
}

void differentbracket(char *calcul, char *baseop)
{
    int open = 0;
    int closed = 0;

    for (int i = 0; calcul[i] != '\0'; i++){
        if (calcul[i] == baseop[0])
            open++;
        else if (calcul[i] == baseop[1])
            closed++;
    }
    if (open != closed){
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_READ);
    }
}

void inbase(char *calcul, char *basea, char *baseb)
{
    for (int i = 0; calcul[i] != '\0'; i++){
        if (charinarray(calcul[i], basea) == 0 &&
            charinarray(calcul[i], baseb) == 0){
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_READ);
        }
    }
}

void error_in_av (char *calcul, char *basenb, char *baseop, int n)
{
    if (my_strlen(calcul) < n || n == 0){
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_READ);
    }
    samebase(basenb, baseop);
    inbase(calcul, basenb, baseop);
    differentbracket(calcul, baseop);
    manyops(calcul, basenb, baseop);
}