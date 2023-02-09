/*
** EPITECH PROJECT, 2021
** create matrix 3x1
** File description:
** create_matrice3x1
*/

#include "architect.h"
#include <math.h>
#include <stdlib.h>

float **create_matrice_3x1(char *arg1, char *arg2)
{
    float **matrix = create_matrix(1, 3);

    matrix[0][0] = atof(arg1);
    matrix[1][0] = atof(arg2);
    matrix[2][0] = 1;
    return matrix;
}