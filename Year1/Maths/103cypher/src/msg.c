/*
** EPITECH PROJECT, 2021
** msg.c
** File description:
** msg
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "cipher.h"

float *msg_to_ascii(char **av, cipher_t *cipher)
{
    float *msg = malloc(sizeof(float) * strlen(av[1]));
    int temp;

    for (int i = 0; i < strlen(av[1]); i++) {
        temp = av[1][i];
        msg[i] = (float)temp;
        cipher->size_msg += 1;
    }
    return msg;
}

float *msg_to_float(char **av, cipher_t *cipher)
{
    float *msg = malloc(sizeof(float) * strlen(av[1]));
    char* temp = malloc(sizeof(char) * 10);
    int k = 0;
    int j = 0;

    for (int i = 0; i < strlen(av[1]); i++) {
        if (av[1][i] == ' '){
            msg[j] = atof(temp);
            // printf("tmp = %s | element = %.2f\n",temp,msg[j]);
            j++;
            k = 0;
        }
        temp[k] = av[1][i];
        temp[k+1] = '\0';
        k++;
    }
    msg[j] = atof(temp);
    cipher->size_msg = j + 1;
    // printf("tmp = %s | element = %.2f\n",temp,msg[j]);
    return msg;
}

float **msg_to_matrix(float *msg, cipher_t *cipher)
{
    cipher->y_msg = ceilf(cipher->size_msg / cipher->size_key);
    float **msg_matrix = create_matrix(cipher->size_key, cipher->y_msg);
    int k = 0;

    for (int i = 0; i < cipher->y_msg; i++) {
        for (int j = 0; j < cipher->size_key; j++) {
            if (k < cipher->size_msg) {
                msg_matrix[i][j] = msg[k];
            } else {
                msg_matrix[i][j] = 0;
            }
            k++;
        }
    }
    return msg_matrix;
}

char *matrice_to_str(float **matrice, cipher_t *cipher)
{
    char *res = malloc(sizeof(char) * cipher->y_msg * cipher->size_key + 1);

    print_array(matrice, cipher->size_msg, 1);
    for (int j = 0; j < cipher->size_msg; j++){
        // printf("y msg : %f\nsize key : %f\n", cipher->y_msg, cipher->size_key);
        // res[k] = (char)matrice[i][j];
        // res[k] = matrice[i][j];

        printf("%c", (char)matrice[0][j]);
    }
    printf("\n");
    return res;
}