/*
** EPITECH PROJECT, 2021
** matrix3x1.c
** File description:
** matrix3x1
*/

float **product_matrix_3x1(float **matrix_one, float **matrix_two)
{
    float **result = malloc(sizeof(float*) * 3);
    result[0] = malloc(sizeof(float) * 1);
    result[1] = malloc(sizeof(float) * 1);
    result[2] = malloc(sizeof(float) * 1);
    result[0][0] = matrix_one[0][0] *  matrix_two[0][0] +  matrix_one[0][1] * matrix_two[1][0] + matrix_one[0][2] * matrix_two[2][0];
    result[1][0] = matrix_one[1][0] *  matrix_two[0][0] +  matrix_one[1][1] * matrix_two[1][0] + matrix_one[1][2] * matrix_two[2][0];
    result[2][0] = matrix_one[2][0] *  matrix_two[0][0] +  matrix_one[2][1] * matrix_two[1][0] + matrix_one[2][2] * matrix_two[2][0];
    return result;
}