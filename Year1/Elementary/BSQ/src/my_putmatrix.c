/*
** EPITECH PROJECT, 2021
** my put matrix.c
** File description:
** put matrix
*/

#include "my.h"

void my_putmatrix(int *matrix, int size)
{
    for (int i = 0; i < size; i++) {
        if (matrix[i] == -1)
            my_putchar('\n');
        else
            my_put_nbr(matrix[i]);
    }
}
