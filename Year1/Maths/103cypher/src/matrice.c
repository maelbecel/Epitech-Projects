/*
** EPiTECH PROjECT, 2021
** matrice.c
** File description:
** produit de matrice
*/

#include "cipher.h"
#include "my.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


float **new_matrice(int ligne, int colonne)
{
    float **mat = malloc(ligne * sizeof(float *));
    for(int i = 0; i < ligne; i++){
        mat[i] = malloc(colonne * sizeof(float));
    }
    return mat;
}

float **product_matrice(float **key, float **mat, cipher_t *cipher)
{
    float **product = new_matrice(cipher->y_msg, cipher->size_key);
    for(int i = 0; i < cipher->y_msg; i++){
        for(int j = 0; j < cipher->size_key; j++) {
            product[i][j] = 0;
            for(int k = 0; k < cipher->size_key; k++) {
                product[i][j] += mat[i][k] * key[k][j];
            }
        }
    }
    float **res = new_matrice(1, cipher->y_msg * cipher->size_key);
    int k = 0;
    for(int i = 0; i < cipher->y_msg; i++){
        for(int j = 0; j < cipher->size_key; j++) {
            res[0][k] = product[i][j];
            k++;
        }
    }
    return res;
}

float det_2x2(float **key)
{
    return ((key[0][0] * key[1][1]) - (key[0][1] * key[1][0]));
}

float det_3x3(float **key)
{
    float tmp = 0;
    tmp += key[0][0] * ((key[1][1] * key[2][2]) - (key[1][2] * key[2][1]));
    tmp -= key[0][1] * ((key[1][0] * key[2][2]) - (key[1][2] * key[2][0]));
    tmp += key[0][2] * ((key[1][0] * key[2][1]) - (key[1][1] * key[2][0]));
    return tmp;
}

float **comatrice_key(float **key)
{
    float **matrix = create_matrix(3, 3);
    matrix[0][0] = (key[1][1] * key[2][2]) - (key[1][2] * key[2][1]);
    matrix[0][1] = ((key[1][0] * key[2][2]) - (key[1][2] * key[2][0])) * -1;
    matrix[0][2] = (key[1][0] * key[2][1]) - (key[1][1] * key[2][0]);
    matrix[1][0] = ((key[0][1] * key[2][2]) - (key[0][2] * key[2][1])) * -1;
    matrix[1][1] = (key[0][0] * key[2][2]) - (key[0][2] * key[2][0]);
    matrix[1][2] = ((key[0][0] * key[2][1]) - (key[0][1] * key[2][0])) * -1;
    matrix[2][0] = (key[0][1] * key[1][2]) - (key[0][2] * key[1][1]);
    matrix[2][1] = ((key[0][0] * key[1][2]) - (key[0][2] * key[1][0])) * -1;
    matrix[2][2] = (key[0][0] * key[1][1]) - (key[0][1] * key[1][0]);
    return matrix;
}

float **transpose_key(float **key)
{
    float tmp = 0;
    tmp = key[1][0];
    key[1][0] = key[0][1];
    key[0][1] = tmp;
    tmp = key[2][0];
    key[2][0] = key[0][2];
    key[0][2] = tmp;
    tmp = key[2][1];
    key[2][1] = key[1][2];
    key[1][2] = tmp;
    return key;
}

float **calcul_inverse_3x3(float **key, float det)
{
    key[0][0] = key[0][0] * (1 / det);
    key[0][1] = key[0][1] * (1 / det);
    key[0][2] = key[0][2] * (1 / det);
    key[1][0] = key[1][0] * (1 / det);
    key[1][1] = key[1][1] * (1 / det);
    key[1][2] = key[1][2] * (1 / det);
    key[2][0] = key[2][0] * (1 / det);
    key[2][1] = key[2][1] * (1 / det);
    key[2][2] = key[2][2] * (1 / det);
    return key;
}

float **inverse_key_2x2(float **key)
{
    float tmp = key[0][0];

    key[0][0] = key[1][1];
    key[0][1] = key[0][1] * -1;
    key[1][0] = key[1][0] * -1;
    key[1][1] = tmp;
    return key;
}

float **calcul_inverse_2x2(float **key, float det)
{
    key[0][0] = key[0][0] * (1 / det);
    key[0][1] = key[0][1] * (1 / det);
    key[1][0] = key[1][0] * (1 / det);
    key[1][1] = key[1][1] * (1 / det);
    return key;
}