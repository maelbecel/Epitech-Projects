/*
** EPITECH PROJECT, 2021
** zaert
** File description:
** zerty
*/

#include <stdlib.h>

float **create_matrix(int x, int y)
{
    float **matrix = malloc(sizeof(float *) * y);

    for(int i = 0; i < y; i++) {
        matrix[i] = malloc(sizeof(float) * x);
    }
    return matrix;
}