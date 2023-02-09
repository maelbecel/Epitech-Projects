/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "cipher.h"
#include "my.h"
#include "printf.h"

void print_array(float **array, int x, int y)
{
    int i = 0;
    int j = 0;

    while (i < y) {
        while (j < x) {
            printf("%-8.0f ", array[i][j]);
            j++;
        }
        j = 0;
        printf("\n");
        i++;
    }
    printf("\n");
}

void print_encrypted(float **array, int x, int y)
{
    int i = 0;
    int j = 0;

    while (i < y) {
        while (j < x) {
            printf("%.0f", array[i][j]);
            j++;
            if (j < x)
                printf(" ");
        }
        j = 0;
        printf("\n");
        i++;
    }
    printf("\n");
}

void print_array_inverse(float **array, int x, int y)
{
    int i = 0;
    int j = 0;

    while (i < y) {
        while (j < x) {
            printf("%-8.3f", array[i][j]);
            j++;
        }
        j = 0;
        printf("\n");
        i++;
    }
    printf("\n");
}

void print_msg(float *msg, cipher_t *cipher)
{
    for (int i = 0; i < cipher->size_msg; i++) {
        printf("%.0f ", msg[i]);
    }
    printf("\n");
}

float **create_matrix(int x, int y)
{
    float **matrix = malloc(sizeof(float *) * y);

    for(int i = 0; i < y; i++) {
        matrix[i] = malloc(sizeof(float) * x);
    }
    return matrix;
}

void encrypt(char **av)
{
    cipher_t *cipher = malloc(sizeof(cipher_t));
    cipher->size_key = 0;
    cipher->size_msg = 0;
    float **key = put_key_to_matrix(av, cipher);
    float *msg = msg_to_ascii(av, cipher);
    float **matrix_msg = msg_to_matrix(msg, cipher);
    printf("Key matrix:\n");
    print_array(key, cipher->size_key, cipher->size_key);
    printf("\nEncrypted message:\n");
    float **produit = product_matrice(key, matrix_msg, cipher);
    print_encrypted(produit, cipher->size_key * cipher->y_msg, 1);
}

void decrypt(char **av)
{
    cipher_t *cipher = malloc(sizeof(cipher_t));
    cipher->size_key = 0;
    cipher->size_msg = 0;
    float **key = put_key_to_matrix(av, cipher);
    float *msg = msg_to_float(av, cipher);
    float **matrix_msg = msg_to_matrix(msg, cipher);
    //printf("det 3x3 : %f\n", det_3x3(key));
    printf("Key matrix:\n");
    print_array(key, cipher->size_key, cipher->size_key);
    if (cipher->size_key == 2){
        float det = det_2x2(key);
        if (det != 0){
            key = inverse_key_2x2(key);
            key = calcul_inverse_2x2(key, det);
        }
    } if (cipher->size_key == 3){
        float det = det_3x3(key);
        if (det != 0){
            key = comatrice_key(key);
            key = transpose_key(key);
            key = calcul_inverse_3x3(key, det);
            print_array_inverse(key, 3, 3);
        }
    }
    printf("Decrypted message:\n");
    float **decode_matrice = product_matrice(key, matrix_msg, cipher);
    // print_array(decode_matrice, cipher->y_msg, cipher->size_key);
    printf("%s",matrice_to_str(decode_matrice, cipher));
    return;
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        printf("USAGE\n\t./103cipher message key flag\n\nDESCRIPTION\n\tmessage\ta message, made of ASCII characters\n\tkey\tthe encryption key, made of ASCII characters\n\tflag\t0 for the message to be encrypted, 1 to be decrypted\n");
    else if (ac == 4) {
        if (av[3][0] == '0') {
            encrypt(av);
            return 0;
        } else if (av[3][0] == '1') {
            decrypt(av);
            return 0;
        }
    }
    return 84;
}