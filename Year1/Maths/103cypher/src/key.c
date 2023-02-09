/*
** EPITECH PROJECT, 2021
** key.c
** File description:
** key
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "cipher.h"

float **put_key_to_matrix(char **av, cipher_t *cipher)
{
    float **key = create_key(av, cipher);
    int j = 0;
    int k = 0;

    for (int i = 0; i < cipher->size_key; i++) {
        for (; j < cipher->size_key; j++) {
            if (k < strlen(av[2])) {
                key[i][j] = av[2][k];
                k++;
            } else {
                key[i][j] = 0;
            }
        }
        j = 0;
    }
    return key;
}

float **create_key(char **av, cipher_t *cipher)
{
    float **key;
    if (strlen(av[2]) == 1) {
        key = create_matrix(1, 1);
        cipher->size_key = 1;
    }
    else if (strlen(av[2]) > 1 && strlen(av[2]) <= 4) {
        key = create_matrix(2, 2);
        cipher->size_key = 2;
    }
    else if (strlen(av[2]) > 4 && strlen(av[2]) <= 9) {
        key = create_matrix(3, 3);
        cipher->size_key = 3;
    }
    return key;
}
