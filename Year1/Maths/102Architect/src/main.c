/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "architect.h"
#include <string.h>
#include <stdio.h>

void print_array(float **array)
{
    int i = 0;
    int j = 0;

    while (i < 3) {
        while (j < 3) {
            printf("%-8.2f", array[i][j]);
            j++;
        }
        j = 0;
        printf("\n");
        i++;
    }
}

void print_res(float **res)
{
    int i = 0;

    while (i < 3) {
        printf("%-8.2f\n", res[i][0]);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        printf("USAGE\n./102architect x y transfo1 arg11 [arg12] [transfo2 arg12 [arg22]] ...\n\nDESCRIPTION\nx abscissa of the original point\ny ordinate of the original point\n\ntransfo arg1 [arg2]\n-t i j translation along vector (i, j)\n-z m n scaling by factors m (x-axis) and n (y-axis)\n-r d rotation centered in O by a d degree angle\n-s d reflection over the axis passing through O with an inclination angle of d degrees\n");
    }
    float **res = create_matrice_3x1(argv[1], argv[2]);
    float **identity = create_identity();
    float **matrix = create_matrix(3,3);
    matrix = print_action(argc, argv, identity);
    float **res_final = product_matrix_3x1(matrix, res);
    print_array(matrix);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", res[0][0], res[1][0], res_final[0][0], res_final[1][0]);
    return 0;
}