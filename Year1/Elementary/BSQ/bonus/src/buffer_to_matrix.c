/*
** EPITECH PROJECT, 2021
** buffer_to_matrix.c
** File description:
** turn an str into a matrix
*/

#include "my.h"
#include "bsq.h"
#include <stdlib.h>

int *buffer_to_matrix(char *str, Len *square)
{
    int i = decal(str);
    int *res = malloc(sizeof(int) * (square->col + 1)*square->line*square->dimensions+square->dimensions + i);
    int j = 0;
    while (str[i] != '\0') {
        if (str[i] == '.'){
            res[j] = 1;
        }else if (str[i] == 'o'){
            res[j] = 0;
        }else if (str[i] == 'd'){
            res[j] = -2;
        }else{
            res[j] = -1;
        }
        i++;
        j++;
    }
    return res;
}