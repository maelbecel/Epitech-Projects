/*
** EPITECH PROJECT, 2021
** matrix§.c
** File description:
** matrix
*/

#include <stdlib.h>

float **product_matrix(float **matrix_one, float **matrix_two)
{
    float **result = malloc(sizeof(float*) * 3);
    result[0] = malloc(sizeof(float) * 3);
    result[1] = malloc(sizeof(float) * 3);
    result[2] = malloc(sizeof(float) * 3);
    result[0][0] = matrix_one[0][0] *  matrix_two[0][0] +  matrix_one[0][1] * matrix_two[1][0] + matrix_one[0][2] * matrix_two[2][0];
    result[0][1] = matrix_one[0][0] *  matrix_two[0][1] +  matrix_one[0][1] * matrix_two[1][1] + matrix_one[0][2] * matrix_two[2][1];
    result[0][2] = matrix_one[0][0] *  matrix_two[0][2] +  matrix_one[0][1] * matrix_two[1][2] + matrix_one[0][2] * matrix_two[2][2];
    result[1][0] = matrix_one[1][0] *  matrix_two[0][0] +  matrix_one[1][1] * matrix_two[1][0] + matrix_one[1][2] * matrix_two[2][0];
    result[1][1] = matrix_one[1][0] *  matrix_two[0][1] +  matrix_one[1][1] * matrix_two[1][1] + matrix_one[1][2] * matrix_two[2][1];
    result[1][2] = matrix_one[1][0] *  matrix_two[0][2] +  matrix_one[1][1] * matrix_two[1][2] + matrix_one[1][2] * matrix_two[2][2];
    result[2][0] = matrix_one[2][0] *  matrix_two[0][0] +  matrix_one[2][1] * matrix_two[1][0] + matrix_one[2][2] * matrix_two[2][0];
    result[2][1] = matrix_one[2][0] *  matrix_two[0][1] +  matrix_one[2][1] * matrix_two[1][1] + matrix_one[2][2] * matrix_two[2][1];
    result[2][2] = matrix_one[2][0] *  matrix_two[0][2] +  matrix_one[2][1] * matrix_two[1][2] + matrix_one[2][2] * matrix_two[2][2];
    return result;
}