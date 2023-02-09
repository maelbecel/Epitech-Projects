/*
** EPITECH PROJECT, 2021
** suce ma bite pour noel
** File description:
** pareil
*/

#include "architect.h"

float **matrix_translation(float **matrix, vector_t *vector)
{
    matrix[0][2] = vector->x;
    matrix[1][2] = vector->y;
    return matrix;
}

float **matrix_scaling(float **matrix, vector_t *vector)
{
    matrix[0][0] = vector->x;
    matrix[1][1] = vector->y;
    return matrix;
}

float **matrix_rotation(float **matrix, angle_t *angle)
{
    matrix[0][0] = angle->x1;
    matrix[0][1] = angle->x2;
    matrix[1][0] = angle->y1;
    matrix[1][1] = angle->y2;
    return matrix;
}

float **matrix_reflection(float **matrix, angle_t *angle)
{
    matrix[0][0] = angle->x1;
    matrix[0][1] = angle->x2;
    matrix[1][0] = angle->y1;
    matrix[1][1] = angle->y2;
    return matrix;
}