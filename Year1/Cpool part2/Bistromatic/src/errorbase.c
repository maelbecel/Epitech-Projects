/*
** EPITECH PROJECT, 2021
** errorbase.c
** File description:
** Error in same base
*/

#include "my.h"
#include "bistromatic.h"
#include <stdlib.h>

void baseequal(char *basea, char *baseb, int i, int j)
{
    if (basea[i] == baseb[j]){
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_READ);
    }
}

void samebase(char *basea, char *baseb)
{
    for (int i = 0; basea[i] != '\0'; i++){
        for (int j = 0; baseb[j] != '\0'; j++){
            baseequal(basea, baseb, i, j);
        }
    }
}